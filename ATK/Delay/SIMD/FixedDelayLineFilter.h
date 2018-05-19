/**
 * \file FixedDelayLineFilter
 */

#ifndef ATK_DELAY_SIMD_FIXEDDELAYLINEFILTER_H
#define ATK_DELAY_SIMD_FIXEDDELAYLINEFILTER_H

#include <memory>

#include <ATK/Core/BaseFilter.h>
#include <ATK/Delay/config.h>

namespace ATK
{
  /// Create a SIMD filter to multiply channels together
  template<typename DataType, gsl::index VL>
  ATK_DELAY_EXPORT std::unique_ptr<BaseFilter> createFixedDelayLineFilter(gsl::index max_delay);
}

#endif
