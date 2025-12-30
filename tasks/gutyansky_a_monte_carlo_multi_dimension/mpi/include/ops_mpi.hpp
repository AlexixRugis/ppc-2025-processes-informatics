#pragma once

#include <vector>

#include "gutyansky_a_monte_carlo_multi_dimension/common/include/common.hpp"
#include "task/include/task.hpp"

namespace gutyansky_a_monte_carlo_multi_dimension {

class GutyanskyAMonteCarloMultiDimensionMPI : public BaseTask {
 public:
  static constexpr ppc::task::TypeOfTask GetStaticTypeOfTask() {
    return ppc::task::TypeOfTask::kMPI;
  }
  explicit GutyanskyAMonteCarloMultiDimensionMPI(const InType &in);

 private:
  static void GetScatterParams(int rank, int world_size, int elements_count, int *size, int *displacement);
  std::vector<int> ScatterA(int rank, int world_size, int rows_a, int cols_a);
  std::vector<int> ScatterB(int rank, int world_size, int rows_b, int cols_b);
  void GatherResult(int rank, int world_size, int rows_a, int cols_b, std::vector<int> &res_buffer);
  bool ValidationImpl() override;
  bool PreProcessingImpl() override;
  bool RunImpl() override;
  bool PostProcessingImpl() override;
};

}  // namespace gutyansky_a_monte_carlo_multi_dimension
