#ifndef MARIO_GAME_MAP_H
#define MARIO_GAME_MAP_H
#include <SFML/Graphics.hpp>
#include "../main.h"

inline std::string TileMap[Height] {
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                   c                                                                                                                                                                                                W",
    "W                                                                                                                                                                                                                                                                    W",
    "W               c                  C                                                                                                                                                                                                                                 W",
    "W                                                                                                                                                                                                                                                                    B",
    "W                                                       c                                                          c                                                                                                                                                 B",
    "W                                                                                  C                                                 C                              c              C                     c                                                           B",
    "W                         3                                                                            c                   3                           c                                                                                                             B",
    "W                                                                      3                                                                                                   3                          I    Z                                                         B",
    "W                                                                                                                                                                                                                                                                   B",
    "W                   0                                                          bbbbbbbb   bbb0              0           bbb    b00b                                                         ss                                                                      B",
    "W                                                                                                                                                                                          sss                                                                      BB",
    "W                                                                                                                                                                                         ssss                                                                      BB",
    "W                                              TW        TW                                                                                                                              sssss                                                                      BB",
    "W             0   b0b0b                        WW        WW                 b0b              b     bb    0  0  0     b          bb      s  s          ss  s            bb0b             ssssss                                                                      BB",
    "W                                     TW       tW        tW                                                                            ss  ss        sss  ss                           sssssss                                                                      BB",
    "W  H                        TW        WW       WW H      WW                                   H                                       sss  sss H    ssss  sss     TW              TW  ssssssss   H                                                                  BB",
    "W           K   h      k g  WW     g  tW 2     tW        tW K    h      k                2                K    h       k             ssssk ssss    sssss  ssss h  WW  k           WW sssssssss        W                                                             BB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


#endif //MARIO_GAME_MAP_H
