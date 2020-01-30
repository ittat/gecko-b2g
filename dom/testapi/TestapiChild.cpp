#include "TestapiChild.h"


#undef LOG
#if defined(MOZ_WIDGET_GONK)
#include <android/log.h>
#define LOG(args...)  __android_log_print(ANDROID_LOG_INFO, "TestapiChild" , ## args)
#else
#define LOG(args...)
#endif


using namespace mozilla;
using namespace mozilla::dom;
using namespace mozilla::dom::testapi;



TestapiChild::TestapiChild(){
  LOG("enter TestapiChild()");
  MOZ_COUNT_CTOR(TestapiChild);

}

 

TestapiChild::~TestapiChild(){
  LOG("enter TestapiChild()");
  MOZ_COUNT_DTOR(TestapiChild);

}
