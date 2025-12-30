#pragma once

#include <string>
#include <utility>

#include "matrix.hpp"
#include "task/include/task.hpp"

namespace gutyansky_a_monte_carlo_multi_dimension {

using InType = std::pair<Matrix, Matrix>;
using OutType = Matrix;
using TestType = std::string;
using BaseTask = ppc::task::Task<InType, OutType>;

}  // namespace gutyansky_a_monte_carlo_multi_dimension
