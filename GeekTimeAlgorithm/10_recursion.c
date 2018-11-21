//
//  10_recursion.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "10_recursion.h"

size_t stepCount(size_t step)
{
    assert(step > 0);
    if (step == 1) {
        return 1;
    }
    else if (step == 2) {
        return 2;
    }
    else {
        return stepCount(step-1) + stepCount(step-2);
    }
}

size_t iterativeStepCount(size_t step)
{
    assert(step > 0);
    if (step == 1) {
        return 1;
    }
    else if (step == 2) {
        return 2;
    }
    else {
        size_t f1 = 1;
        size_t f2 = 2;
        for (size_t i = 3; i < step; i++) {
            size_t temp = f1;
            f1 = f2;
            f2 = temp + f1;
        }
        return f1 + f2;
    }
}
