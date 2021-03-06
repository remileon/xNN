/*
 * loss_layer.hpp
 *
 *  Created on: 2016��6��5��
 *      Author: Administrator
 */

#ifndef LOSS_LAYER_HPP_
#define LOSS_LAYER_HPP_

#include <vector>

#include "hidden_neuron.hpp"

using std::vector;

template<typename DType, template <typename> class Loss, template <typename> class PartialLoss>
class LossLayer {
	Loss<DType> m_foLoss;
	PartialLoss<DType> m_foPartialLoss;
public:
	LossLayer();
	~LossLayer();

	inline void foreward(HiddenNeuron<DType> * down) {
		// down.active = Loss(down.output)
		m_foLoss(down->getMutableActive(), down->getOutput(), down->getVecLen());
	}
	
	inline void backward(HiddenNeuron<DType> * down, int correctLabel) {
		// down.output_diff = partialLoss(down.active, up.correct)
		m_foPartialLoss(down->getMutableOutputDiff(), down->getActive(), correctLabel, down->getVecLen());
	}
};

// definitions

template<typename DType, template <typename> class Loss, template <typename> class PartialLoss>
LossLayer<DType, Loss, PartialLoss>::LossLayer() {

}

template<typename DType, template <typename> class Loss, template <typename> class PartialLoss>
LossLayer<DType, Loss, PartialLoss>::~LossLayer() {

}
#endif /* LOSS_LAYER_HPP_ */
