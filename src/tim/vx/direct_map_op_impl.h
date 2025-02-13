/****************************************************************************
*
*    Copyright (c) 2021 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/
#ifndef TIM_VX_DIRECT_MAP_OP_IMPL_H_
#define TIM_VX_DIRECT_MAP_OP_IMPL_H_

#include "vsi_nn_pub.h"
#include "graph_private.h"

#include "op_impl.h"

namespace tim {
namespace vx {

class DirectMapOpImpl : public OpImpl {
 public:
  // DirectMapOpImpl(Graph* graph, uint32_t kind, int input_cnt = 0,
  //               int output_cnt = 0);
  DirectMapOpImpl(Graph* graph, uint32_t kind, int input_cnt = 0,
                  int output_cnt = 0, DataLayout layout = DataLayout::ANY);
  ~DirectMapOpImpl() {}

  DirectMapOpImpl& BindInput(const std::shared_ptr<Tensor>& tensor) override;
  DirectMapOpImpl& BindOutput(const std::shared_ptr<Tensor>& tensor) override;

  vsi_nn_node_t* node() override { return this->node_; }

  void SetRoundingPolicy(
      OverflowPolicy overflow_policy = OverflowPolicy::SATURATE,
      RoundingPolicy rounding_policy = RoundingPolicy::RTNE,
      RoundType down_scale_size_rounding = RoundType::FLOOR,
      uint32_t accumulator_bits = 0);

  std::vector<std::shared_ptr<Tensor>> InputsTensor() override {
    return inputs_tensor_;
  }
  std::vector<std::shared_ptr<Tensor>> OutputsTensor() override {
    return outputs_tensor_;
  }

 protected:
  vsi_nn_node_t* node_{nullptr};
};

}  // namespace vx
}  // namespace tim

#endif /* TIM_VX_DIRECT_MAP_OP_IMPL_H_ */
