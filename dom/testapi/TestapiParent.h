#ifndef mozilla_dom_testapi_TestapiParent_h
#define mozilla_dom_testapi_TestapiParent_h
 

#include "mozilla/dom/testapi/PTestapiParent.h"

#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "mozilla/dom/DOMRequest.h"


namespace mozilla {
namespace dom {
namespace testapi {

class TestapiParent :public PTestapiParent
                    ,public nsISupports
{

public:

  NS_DECL_ISUPPORTS

  TestapiParent();

  virtual void ActorDestroy(ActorDestroyReason aWhy) override;

protected:

  virtual ~TestapiParent();
  /*receive child function call*/
  virtual bool RecvSetTestData(const nsString& cmd, nsString* rv) override;  

 

};

 

}// namespace aaatest
}// namespace dom
}// namespace testapi


#endif /*mozilla_dom_aaatest_AaaTestParent_h*/

