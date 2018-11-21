//
//  00_string.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/19.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "00_string.h"

static void string_reverse(char *s, int length)
{
    for(int i = 0; i <= (length-1)/2; i++) {
        char temp = s[i];
        s[i] = s[length-i-1];
        s[length-i-1] = temp;
    }
}

// 用的是(X'Y')' = YX的逻辑
void string_left_swift(char *s, int bit)
{
    assert(s!=NULL&&bit>=0);
    int length = strlen(s);
    bit %= length;
    string_reverse(s, bit);
    string_reverse(&s[bit], length-bit);
    string_reverse(s, length);
}
