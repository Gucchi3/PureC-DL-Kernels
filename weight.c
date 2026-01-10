#include "Tensor.h"

/*----------------------------------------------
weight.c：重みデータとW_Tensor/B_Tensor構造体を定義する場所

explanation：
　ここで、重みデータ（const float配列）と、それを参照する
　W_Tensor/B_Tensorを定義します。
　main.cにて「Patch_embedding(feat1, &patch_weight);」のように
　引数で渡して使用します。

作成例：
  // 重みデータ
  static const float patch_embed_weight[48] = { ... };

  // 構造体定義
  W_Tensor patch_weight = {
    .OC = 3,
    .INC = 3,
    .H = 4,
    .W = 4,
    .data = patch_embed_weight
  };

------------------------------------------------*/


// =================================================================
// Patch Embedding / Conv Weight Data
// =================================================================
static const float patch_embed_weight[81] = {
    // OC=0
    // 行0 (Top)
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
    // 行1 (Center) -> 真ん中のInput Ch0だけ 1.0
    0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
    // 行2 (Bottom)
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,

    // OC=1
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,

    // OC=2
    1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 0.0f,   100.0f, 100.0f, 100.0f
};

static const float conv1_bias_data[3] = { 0.1f, -0.5f, 0.01f };

W_Tensor patch_weight = {
    .OC = 3,
    .INC = 3,
    .H = 3,
    .W = 3,
    .data = patch_embed_weight
};

B_Tensor conv_bias = {
    .OC = 3,
    .data = conv1_bias_data
};


// =================================================================
// Linear Debug Weight Data
// =================================================================
// 入力想定: 8x8x3 = 192要素 (値は 0.0, 1.0, ..., 191.0)
// 出力: 2要素
// =================================================================
static const float linear_debug_weight_data[384] = {
    // --- OC 0 : ゼロ和・負数・小数テスト ---
    // Target: Input[10]=10, Input[11]=11, Input[20]=20
    // Calc: (10*0.5) + (11*-0.5) + (20*0.25) 
    //     = 5.0 - 5.5 + 5.0 = 4.5
    [10] = 0.5f,
    [11] = -0.5f,
    [20] = 0.25f,

    // --- OC 1 : 桁の異なる加算テスト ---
    // Offset 192 start
    // Target: Input[100]=100, Input[101]=101
    // Calc: (100 * 0.1) + (101 * 10.0)
    //     = 10.0 + 1010.0 = 1020.0
    [192 + 100] = 0.1f,
    [192 + 101] = 10.0f
};

static const float linear_debug_bias_data[2] = { 
    -4.5f,  // OC0: 4.5 + (-4.5) = 0.0
    5.55f   // OC1: 1020.0 + 5.55 = 1025.55
};

W_Tensor linear_weight = {
    .OC = 2,
    .INC = 3,   // 入力のチャンネル数
    .H = 8,     // 入力の高さ
    .W = 8,     // 入力の幅
    .data = linear_debug_weight_data
};

B_Tensor linear_bias = {
    .OC = 2,
    .data = linear_debug_bias_data
};