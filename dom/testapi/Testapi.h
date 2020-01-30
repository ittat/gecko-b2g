#ifndef mozilla_dom_testapi_Testapi_h
#define mozilla_dom_testapi_Testapi_h

#include "nsISupports.h"
#include "nsPIDOMWindow.h"
#include "nsWrapperCache.h"


//#include "Types.h"

#include "TestapiChild.h"


//#include <android/log.h>

#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


using namespace std;

namespace mozilla{
namespace dom{


namespace testapi{

class PTestapiChild;
class PTestapiParent;


class Testapi final
                        :public nsISupports
                        ,public nsWrapperCache
{

public:

  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(Testapi)

  explicit Testapi(nsPIDOMWindow* aWindow); //构造函数


  nsPIDOMWindow* GetParentObject()const{return mWindow;}

//  virtual JSObject* WrapObject(JSContext* aCx) override;
  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  /* Impliment the WebIDL interface begin*/
  bool Vl() const;

  NS_IMETHODIMP SetTestData();
 
  bool  ReturnBoolean(bool aaa);

  void  Exec(const nsAString& cmd, nsString& rv);
  /* Imppliment the WebIDL interface end*/


private:



  PTestapiChild* SSGetTestapiChild();
  PTestapiChild* mTestapiChild;

protected:
  virtual ~Testapi();//析构函数

  nsCOMPtr<nsPIDOMWindow> mWindow;


};

}// namespace testapi
}// namespace dom
}// namespace mozilla
#endif
