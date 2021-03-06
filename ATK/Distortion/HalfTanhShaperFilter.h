/**
 * \file HalfTanhShaperFilter.h
 */

#ifndef ATK_DISTORTION_HALFTANHSHAPERFILTER_H
#define ATK_DISTORTION_HALFTANHSHAPERFILTER_H

#include <ATK/Core/TypedBaseFilter.h>
#include <ATK/Distortion/config.h>

namespace ATK
{
  /// Negative half of the signal tanh mapper
  template<typename DataType_>
  class ATK_DISTORTION_EXPORT HalfTanhShaperFilter final : public TypedBaseFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    using Parent = TypedBaseFilter<DataType_>;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::outputs;
    using Parent::nb_input_ports;
    using Parent::nb_output_ports;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;

  public:
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    */
    HalfTanhShaperFilter(gsl::index nb_channels = 1);
    /// Destructor
    ~HalfTanhShaperFilter() override;
    
    void set_coefficient(DataType coeff);
    DataType_ get_coefficient() const;
    
  protected:
    void process_impl(gsl::index size) const final;
  private:
    DataType coeff;
  };
}

#endif
