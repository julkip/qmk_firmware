# julkip's layout for de variant neo2

This layout is designed to be used mainly with [Neo2](http://www.neo-layout.org). There are additional layers, to emulate Neo2 in hardware, if no corresponding keymap is available. The last layer is for using the left part of Ergodox EZ for gaming.

## Build & install

```
make clean
make julkip_de_neo2
teensy-loader-cli -mmcu=atmega32u4 -w ../../.build/ergodox_ez_julkip_de_neo2.hex
```

## Layers

The way you switch through layers is by rotating through layer 0, 1 and 4 by pressing the layer switch button. Layers 2 and 3 can only be accessed through layer 1, since they are emulating Neo2's Mod3 and Mod4 layers.

### Layer0: Neo

```
,--------------------------------------------------.           ,--------------------------------------------------.
|  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  |   -    |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|  Tab   |   X  |   V  |   L  |   C  |   W  | BKSP |           |  DEL |   K  |   H  |   G  |   F  |   Q  |   ß    |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|  M3l   |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|  LSft  |   Ü  |   Ö  |   Ä  |   P  |   Z  | RET  |           | RET  |   B  |   M  |   ,  |   .  |   J  |  RSft  |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | LCtl |  F1  |  F2  |  F3  |  F4  |                                       |   ←  |   ↓  |   ↑  |  →   | RCtl |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |  F5  |  F6  |       |  F7  |  F8  |
                                ,------|------|------|       |------+------+------.
                                |      |      | LAlt |       |  L1  |      |      |
                                | Space|  M3l |------|       |------|  M4r | Space|
                                |      |      | LGui |       | RGui |      |      |
                                `--------------------'       `--------------------'
```

This Layer provides most of Neo2's functionality. Some compromises had to be made, because Ergodox is not full width on the right side. For example the compose keys have been stripped and the modifiers for Mod3 are only on the left hand (with thumb access for inputting left hand symbols) and Mod4 is only on the right hand side. Since I use mainly the i3 window manager, I heavily rely on using LGui and RGui for all windowing operations and the F-Keys for virtual desktop management. Hence they are present in the main layout. However, I have opted to substitute F9-F12 with hjkl-style arrow keys, because there are some programs that don't work well with Neo2's Mod4 arrow keys (I'm looking at you, Dwarf Fortress).

### Layer1: Poor man's Neo2

```
,--------------------------------------------------.           ,--------------------------------------------------.
|  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  |   -    |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|  Tab   |   X  |   V  |   L  |   C  |   W  | BKSP |           |  DEL |   K  |   H  |   G  |   F  |   Q  |   ß    |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|  (L2)  |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|  LSft  |   Ü  |   Ö  |   Ä  |   P  |   Z  | RET  |           | RET  |   B  |   M  |   ,  |   .  |   J  |  RSft  |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | Prnt |  F1  |  F2  |  F3  |  F4  |                                       |   ←  |   ↓  |   ↑  |  →   | RCtl |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |  F5  |  F6  |       |  F7  |  F8  |
                                ,------|------|------|       |------+------+------.
                                |      |      | LAlt |       |  L4  |      |      |
                                | LSft | (L2) |------|       |------| (L3) | Space|
                                |      |      | LGui |       | RGui |      |      |
                                `--------------------'       `--------------------'
```

This layer is intended for use on systems which do not run Neo2 natively, such as fresh installs, EFI command promts and other peoples computers.

### Layer2: Poor man's Neo2 - Mod3
```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |      |  _   |  [   |  ]   |  ^   |      |           |      |      |  <   |  >   |  =   |  &   |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |  \   |  /   |  {   |  }   |  *   |------|           |------|  ?   |  (   |  )   |  -   |  :   |  @     |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |  #   |  $   |  |   |  ~   |  `   |      |           |      |  +   |  %   |  "   |  '   |  ;   |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      | LAlt |       | RCtrl|      |      |
                                | LSft |      |------|       |------|      |  0   |
                                |      |      | LGui |       | RGui |      |      |
                                `--------------------'       `--------------------'

```

Only accessable through layer 1, by holding Mod3

### Layer3: Poor man's Neo2 - Mod4
```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        | PgUp | BSpc |  Up  |  Del | PgDn |      |           |      |      |  7   |  8   |  9   |  +   |  -     |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        | Home | Left | Down | Right|  End |------|           |------|      |  4   |  5   |  6   |  ,   |  .     |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |  Esc |  Tab |  Ins |  Ret | Undo |      |           |      |      |  1   |  2   |  3   |      |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.       ,-------------.
                                       |      |      |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      | LAlt |       |      |      |      |
                                |  0   |      |------|       |------|      |  0   |
                                |      |      | LGui |       | RGui |      |      |
                                `--------------------'       `--------------------'
```

Only accessable through layer 1, by holding Mod4

### Layer4: Qwert(y/z) gaming on neo
```
,--------------------------------------------------.           ,------------------------------------------------  --.
|  ESC   |  1   |  2   |  3   |  4   |  5   |  6   |           |      |      |      |      |      |      |          |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+------  --|
|  Tab   |  P   |  Q   |  W   |  E   |  R   |      |           |      |      |      |      |      |      |          |
|--------+------+------+------+------+------| BkSp |           |      |------+------+------+------+------+------  --|
|        |  I   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |          |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+------  --|
|  LSft  |  M   |  Z   |  X   |  C   |  V   | Ret  |           |      |      |      |      |      |      |          |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+------  --'
  | LCtl |  F1  |  F2  |  F3  |  F4  |                                       |      |      |      |      |        |
  `----------------------------------'                                       `----------------------------------  '
                                       ,-------------.       ,-------------.
                                       |  F5  |  F6  |       |      |      |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       | L0   |      |      |
                                | Spc  | LAlt |------|       |------|      |      |
                                |      |      | LGui |       |      |      |      |
                                `--------------------'       `--------------------'
```

In QWERT(Y/Z) terms, I don't wuse WASD for gaming, I use ESDF. This layer represents a QWERTZ layout which is shifted one column to the right, so that I don't have to reconfigure most games to fit my playstyle. The additional leftmost column is populated with some keys, that are commonly used in many games (M for map view, I for inventory…)
