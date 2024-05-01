#ifndef MARIO_GAME_MAP_H
#define MARIO_GAME_MAP_H
#include <SFML/Graphics.hpp>

#define Height 24
#define Width 263

inline std::string TileMap[Height] {
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    W",
    "W                                                                                                                                                                                                                                                                    B",
    "W          C                                                                                                                                                                                                                                                         B",
    "W                                                                                                                                                                                                                                                                    B",
    "W                                                                                                                                                                                                                                                                    B",
    "W                                                                                                                                                                                                                                                                    B",
    "W                                                                                                                                                                                                                                                                   B",
    "W                   0                                                          BBBBBBBB   BBB0              0           BBB    B00B                                                         BB                                                                      B",
    "W                                                                                                                                                                                          BBB                                                                      BB",
    "W                                                                                                                                                                                         BBBB                                                                      BB",
    "W                                              TW        TW                                                                                                                              BBBBB                                                                      BB",
    "W             0   B0B0B                        WW        WW                 B0B              B     BB    0  0  0     B          BB      B  B          BB  B            BB0B             BBBBBB                                                                      BB",
    "W                                     TW       tW        tW                                                                            BB  BB        BBB  BB                           BBBBBBB                                                                      BB",
    "W      G                    TW        WW       WW        WW                                                                           BBB  BBB      BBBB  BBB     TW              TW  BBBBBBBB                                                                      BB",
    "W                           WW        tW       tW        tW                                                                          BBBB  BBBB    BBBBB  BBBB    WW              WW BBBBBBBBB                                                                       BB",
    "BBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};


#endif //MARIO_GAME_MAP_H
