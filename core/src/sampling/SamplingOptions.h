/*-------------------------------------------------------------------------------
  This file is part of generalized random forest (grf).

  grf is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grf is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grf. If not, see <http://www.gnu.org/licenses/>.
 #-------------------------------------------------------------------------------*/

#ifndef GRF_SAMPLINGOPTIONS_H
#define GRF_SAMPLINGOPTIONS_H


#include <string>
#include <vector>

#include "commons/globals.h"

namespace grf {

class SamplingOptions {
public:
  SamplingOptions();
  SamplingOptions(uint samples_per_cluster,
                  const std::vector<size_t>& clusters);

  const std::vector<double>& get_sample_weights() const;

  /**
   * A map from each cluster ID to the set of sample IDs it contains.
   */
  const std::vector<std::vector<size_t>>& get_clusters() const;

  /**
   * The number of samples that should be drawn from each cluster when
   * training trees.
   */
  uint get_samples_per_cluster() const;
  
  uint get_block_length() const;
  uint get_block_num() const;
  void set_block_length(uint _block_length);
  void set_block_num(uint _block_num);
  bool is_no_overlap() const;
  void set_no_overlap(bool _no_overlap);

private:
  std::vector<double> sample_weights;
  uint num_samples_per_cluster;
  std::vector<std::vector<size_t>> clusters;
  uint block_length = 1;
  uint block_num = 0;
  bool no_overlap = false;
};

} // namespace grf

#endif //GRF_SAMPLINGOPTIONS_H
