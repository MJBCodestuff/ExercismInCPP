#include "gigasecond.h"

#include <boost/date_time/posix_time/time_formatters.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>

namespace gigasecond {
    boost::posix_time::ptime advance(boost::posix_time::ptime time)
{
    return time + boost::posix_time::seconds(1'000'000'000);
}
}  // namespace gigasecond
