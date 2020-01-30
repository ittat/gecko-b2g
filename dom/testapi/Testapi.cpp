#include "Testapi.h"
#include "mozilla/dom/TestapiBinding.h"
#include "mozilla/dom/DOMRequest.h" //already_AddRefed<DOMRequest> ???


#include "nsXULAppAPI.h"//判断是否主进程
#include "mozilla/dom/ContentChild.h"//利用PContent构造child类

//#define LOG(args...)  __android_log_print(ANDROID_LOG_INFO, "AAAAAapiAAAAAA" , ## args)

#undef LOG
#if defined(MOZ_WIDGET_GONK)
#include <android/log.h>
#define LOG(args...)  __android_log_print(ANDROID_LOG_INFO, "Testapi" , ## args)
#else
#define LOG(args...)
#endif

using namespace std;

using namespace mozilla;
using namespace mozilla::dom;
using namespace mozilla::dom::testapi;

 

// cycle collector与isupports的宏定义
NS_IMPL_CYCLE_COLLECTION_CLASS(Testapi)

NS_IMPL_CYCLE_COLLECTION_UNLINK_BEGIN(Testapi)
  NS_IMPL_CYCLE_COLLECTION_UNLINK_PRESERVED_WRAPPER
NS_IMPL_CYCLE_COLLECTION_UNLINK_END

NS_IMPL_CYCLE_COLLECTION_TRAVERSE_BEGIN(Testapi)
  NS_IMPL_CYCLE_COLLECTION_TRAVERSE_SCRIPT_OBJECTS
NS_IMPL_CYCLE_COLLECTION_TRAVERSE_END

NS_IMPL_CYCLE_COLLECTION_TRACE_BEGIN(Testapi)
  NS_IMPL_CYCLE_COLLECTION_TRACE_PRESERVED_WRAPPER
NS_IMPL_CYCLE_COLLECTION_TRACE_END

NS_INTERFACE_MAP_BEGIN_CYCLE_COLLECTION(Testapi)
  NS_WRAPPERCACHE_INTERFACE_MAP_ENTRY
  NS_INTERFACE_MAP_ENTRY(nsISupports)
NS_INTERFACE_MAP_END

NS_IMPL_CYCLE_COLLECTING_ADDREF(Testapi)
NS_IMPL_CYCLE_COLLECTING_RELEASE(Testapi)


 
// 构造函数与析构函数的实现
Testapi::Testapi(nsPIDOMWindow* aWindow)
    : mWindow(aWindow)
{
	LOG("Testapi::Testapi");
	mTestapiChild = NULL;

}

Testapi::~Testapi()
{
	LOG("Testapi::~Testapi");
 	mTestapiChild = NULL;
}

 
// WrapObject的实现
JSObject*
Testapi::WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto)
{
	LOG("Testapi::WrapObject");
	return TestapiBinding::Wrap(aCx, this, aGivenProto);
}

 
// webidl中定义的接口的实现

bool
Testapi::Vl() const
{
	LOG("Testapi::Vl()");
	return true;
}




NS_IMETHODIMP Testapi::SetTestData(){
  LOG("Testapi::SetTestData");
return NS_OK;

}



// 获取child的实例，利用PContent中的构造函数
PTestapiChild*
Testapi::SSGetTestapiChild(){
  if(!mTestapiChild){
    mTestapiChild = ContentChild::GetSingleton()->SendPTestapiConstructor();//this
  }
  return mTestapiChild;
}





bool
Testapi::ReturnBoolean(bool aaa){
  __android_log_print(ANDROID_LOG_INFO, "testapi", "%s", "Testapi::ReturnBoolean");
  return aaa;
}



void   
Testapi::Exec(const nsAString& cmd, nsString& rv)
{
  // 判断是否主进程
  if(GeckoProcessType_Default == XRE_GetProcessType()){
    //从b2g进程进来会进入main
    LOG("main process come in !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  }else{
      // 从非b2g进程进来会进入child
      LOG("child process");
      //child直接调用send函数发送消息，parent会收到消息，调用Recv函数。
	rv.Assign(ToNewUnicode(cmd));
	SSGetTestapiChild()->SendSetTestData(rv, &rv);

  	//if (!SSGetTestapiChild()->SendSetTestData(rv, &rv)) {
   	// aRv.Throw(NS_ERROR_FAILURE);
  	//  return;
 	 //}
  }
}





