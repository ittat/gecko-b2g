#ifndef mozilla_dom_testapi_TestapiChild_h
#define mozilla_dom_testapi_TestapiChild_h
 

#include "mozilla/dom/testapi/PTestapiChild.h"

namespace mozilla {
namespace dom {
namespace testapi {

class TestapiChild :public PTestapiChild
{

public:

  TestapiChild();


protected:

  virtual ~TestapiChild();

 

};

 

}// namespace testapi
}// namespace dom
}// namespace mozilla


#endif 
