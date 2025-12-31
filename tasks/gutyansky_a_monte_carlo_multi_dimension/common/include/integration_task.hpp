#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <tuple>
#include <vector>

#include "gutyansky_a_monte_carlo_multi_dimension/common/include/function_registry.hpp"

namespace gutyansky_a_monte_carlo_multi_dimension {

struct IntegrationTask {
  size_t func_id;
  size_t n_dims;
  std::vector<double> lower_bounds;
  std::vector<double> upper_bounds;
  size_t n_points;

  [[nodiscard]] bool IsValid() const {
    if (n_dims == 0) {
      return false;
    }

    if (n_points == 0) {
      return false;
    }

    if (lower_bounds.size() != n_dims || upper_bounds.size() != n_dims) {
      return false;
    }

    for (size_t i = 0; i < n_dims; i++) {
      if (lower_bounds[i] >= upper_bounds[i]) {
        return false;
      }
    }

    auto func = FunctionRegistry::GetIntegralFunction(func_id);

    if (!func.has_value()) {
      return false;
    }

    FunctionRegistry::FunctionDescription descr = func.value();

    return descr.n_dims == 0 || descr.n_dims == n_dims;
  }

  [[nodiscard]] FunctionRegistry::IntegralFunction GetFunction() const {
    return FunctionRegistry::GetIntegralFunction(func_id).value().func;
  }

  friend bool operator==(const IntegrationTask &t_left, const IntegrationTask &t_right) {
    return t_left.n_dims == t_right.n_dims && t_left.func_id == t_right.func_id &&
           t_left.lower_bounds == t_right.lower_bounds && t_left.upper_bounds == t_right.upper_bounds &&
           t_left.n_points == t_right.n_points;
  }
};

}  // namespace gutyansky_a_monte_carlo_multi_dimension
