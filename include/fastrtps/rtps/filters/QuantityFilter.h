#ifndef THROTTLE_FILTER_H
#define THROTTLE_FILTER_H

#include <fastrtps/rtps/filters/FlowFilter.h>
#include <thread>

/*
 * Simple filter that only clears the first N changes.
 */
namespace eprosima{
namespace fastrtps{
namespace rtps{

class QuantityFilter : public FlowFilter
{
   public:
   explicit QuantityFilter(unsigned int quantityToClear);
   virtual std::vector<const CacheChange_t*> operator()(std::vector<const CacheChange_t*>);

   private:
   unsigned int mQuantity;
};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif
