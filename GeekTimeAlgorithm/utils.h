//
//  utils.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef utils_h
#define utils_h

void swap_array(int *array, size_t i, size_t j);

void traverArray(int *array, size_t length);
// 请自行释放哦
int *rand_array(size_t length);

bool is_ordered(int *array, size_t length, bool asc);
#endif /* utils_h */
