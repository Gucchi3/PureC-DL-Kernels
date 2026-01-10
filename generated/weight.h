#ifndef WEIGHT_H
#define WEIGHT_H

#include "../C_core/include/core/Tensor.h"

/*----------------------------------------------
weight.h：重み構造体のextern宣言

explanation：
　weight.cで定義された重みテンソル（W_Tensor, B_Tensor）の
　extern宣言を記述します。
　main.cなどで「Patch_embedding(feat1, &patch_weight);」のように
　引数で渡して使用します。
------------------------------------------------*/

// =================================================================
// Patch Embedding / Conv Weights
// =================================================================
extern W_Tensor patch_weight;
extern B_Tensor conv_bias;

// =================================================================
// Linear Weights
// =================================================================
extern W_Tensor linear_weight;
extern B_Tensor linear_bias;

#endif