#include "TestapiParent.h"

#include "Testapi.h"

#undef LOG
#if defined(MOZ_WIDGET_GONK)
#include <android/log.h>
#define LOG(args...)  __android_log_print(ANDROID_LOG_INFO, "TestapiParent" , ## args)
#else
#define LOG(args...)
#endif



namespace mozilla {
namespace dom {
namespace testapi {

  NS_INTERFACE_MAP_BEGIN(TestapiParent)
  NS_INTERFACE_MAP_ENTRY(nsISupports)
  NS_INTERFACE_MAP_END
  NS_IMPL_ADDREF(TestapiParent)
  NS_IMPL_RELEASE(TestapiParent)
 

TestapiParent::TestapiParent(){
  LOG("enter TestapiParent()");
  MOZ_COUNT_CTOR(TestapiParent);

}

 

TestapiParent::~TestapiParent(){
  LOG("enter ~TestapiParent() ");
  MOZ_COUNT_DTOR(TestapiParent);
}

void
TestapiParent::ActorDestroy(ActorDestroyReason aWhy){
}


bool
TestapiParent::RecvSetTestData(const nsString& cmd, nsString* rv){

  LOG("enter RecvSetTestData()");

  char buffer[1024];
  LOG("popen");
  FILE  *fp=popen(NS_ConvertUTF16toUTF8(cmd).get(),"r");
  usleep(100000);
  LOG("fgets");
  fgets(buffer,sizeof(buffer),fp);
  usleep(100000);
  LOG("pclose");
  pclose(fp);
  LOG("buffer:%s",buffer);
  LOG("pclose end");

  *rv = NS_ConvertUTF8toUTF16(buffer);


  return true;
}

 

}// namespace testapi
}// namespace dom
}// namespace mozilla mozilla

