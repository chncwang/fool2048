/*
 * uct_player.h
 *
 *  Created on: May 11, 2014
 *      Author: chncwang
 */

#ifndef SRC_PLAYER_UCT_PLAYER_H_
#define SRC_PLAYER_UCT_PLAYER_H_

#include <cstdint>

#include <ostream>
#include <unordered_map>

#include "board/board.h"
#include "board/def.h"
#include "board/location/orientation.h"
#include "player/moving_player.h"

namespace fool2048 {

namespace player {

class UctPlayer : public MovingPlayer {
public:
  UctPlayer() = default;
  ~UctPlayer() = default;

  board::location::Orientation
  NextMove(const board::FullBoard &full_board) const;

protected:

  class NodeRecord {
  public:
    typedef int32_t Times;

    static const board::HashKey kNullHashKey;

    NodeRecord();

    NodeRecord(Times visited_times, float average);

    NodeRecord(const NodeRecord & node_record) = default;

    Times VisitedTimes() const {
      return visited_times_;
    }

    void SetVisitedTimes(Times visited_times) {
      visited_times_ = visited_times;
    }

    float AverageProfit() const {
      return average_profit_;
    }

    void SetAverageProfit(float average_profit) {
      average_profit_ = average_profit;
    }

  private:
    Times visited_times_;
    float average_profit_;

    friend std::ostream& operator<<(std::ostream& out,
        const NodeRecord & node_record);
  };

private:
  static const int kMonteCarloGameCount;

  float NewProfit(board::FullBoard *node, int *mc_count) const;

  board::location::Orientation BestChild(const board::FullBoard &node) const;

  board::location::Orientation
  MaxUcbMove(const board::FullBoard &node) const;

  board::HashKey ChildHashKey(const board::FullBoard &node,
      board::location::Orientation orientation) const;

  float UcbValue(const UctPlayer::NodeRecord & node_record,
      int visited_time_sum) const;

  friend std::ostream& operator<<(std::ostream& out,
      const NodeRecord & node_record);

  NodeRecord &operator=(const NodeRecord &) = delete;

  mutable std::unordered_map<board::HashKey, NodeRecord> transposition_table_;
};

} /* namespace player */
} /* namespace fool2048 */

#endif /* SRC_PLAYER_UCT_PLAYER_H_ */
