// Copyright 2010-2022 Google LLC
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef OR_TOOLS_MATH_OPT_CPP_ID_MAP_TEST_H_
#define OR_TOOLS_MATH_OPT_CPP_ID_MAP_TEST_H_

#include "gtest/gtest.h"
#include "ortools/math_opt/cpp/variable_and_expressions.h"
#include "ortools/math_opt/storage/model_storage.h"

namespace operations_research {
namespace math_opt {

// Test fixture that creates a two models and one VariableMap<double>.
//
// The first model is storage_ has three variables a_, b_ and c_. A
// VariableMap<double> is defined with the following values:
//   - a_: 3.0
//   - c_: 5.0
//
// The second model is other_storage_. It has only one variable, other_d_.
class SimpleIdMapTest : public ::testing::Test {
 public:
  SimpleIdMapTest()
      : a_(&storage_, storage_.AddVariable("a")),
        b_(&storage_, storage_.AddVariable("b")),
        c_(&storage_, storage_.AddVariable("c")),
        vmap_(&storage_, {{a_.typed_id(), 3.0}, {c_.typed_id(), 5.0}}),
        other_d_(&other_storage_, other_storage_.AddVariable("d")) {}

 protected:
  ModelStorage storage_;
  const Variable a_;
  const Variable b_;
  const Variable c_;

  VariableMap<double> vmap_;

  ModelStorage other_storage_;
  const Variable other_d_;
};

using SimpleIdMapDeathTest = SimpleIdMapTest;

}  // namespace math_opt
}  // namespace operations_research

#endif  // OR_TOOLS_MATH_OPT_CPP_ID_MAP_TEST_H_
