# MrKeeb's minivan layout

_DISCLAIMER:_ This layout is heavily inspired on [jetpacktuxedo's layout](https://github.com/qmk/qmk_firmware/tree/master/keyboards/tv44/keymaps/jetpacktuxedo).

This differs quite a bit from the stock layout but leaves keys in a more familiar position in my opinion. It is designed to use the arrow+command layout, but I used a fairly similar layout for the normal arrow layout. Additionally, I use an mx lock switch on the key between the right space key and the arrow cluster. If you don't want to use a lock switch you should change MO(4) on the base layer to use TG(4) instead for a similar effect.

This layout has also been customized to better match macOS in a few ways: the Alt and Win keys have been refersed and both volume and brightness controls have been added to Layer 2.

Finally, full LED support for revisions that use pin B7. Using the right Alt key (mapped to layer 4) with G (on/off), H (increase brightness), L (decrease) and K (breathing).

## Base Layer (0)

The base layer is pretty simple, straight qwerty layout where available. Of note: /? is to the right of the arrow keys. Yes this is kinda weird sometimes, but you get used to it. Tab is tab when pressed and fn2 when held, Enter is the same. GESC is esc when used alone, but ~ when shifted. Tapping FN 1 is space

```text
|GESC| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | BSPC |
| TAB | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  |ENTER|
|SHIFT | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | UP | /  |
|CTRL |ALT   |WIN  |   FN 1   |  SPACE | FN 4  |LEFT|DOWN|RIGH|
```

## Numeric Layer (1)

This layer has the numrow as well as swapping the arrow keys for a nav cluster, and swapping ;: for '" and /? for \|. With that almost all of the missing keys are accounted for.

```text
| `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |  DEL |
|     |    |    |    |    |    |    |    | -  | =  | '  |     |
|      |    |    |    |    |    |    |    | [  |  ] |PGUP| \  |
|    |    |    |    |          |        |      |HOME|PGDN|END |
```

## Symbolic and Volume/Brightness Control Layer (2)

I don't want to be using two key combos constantly, so I also added this symbol layer that is basically shift+numeric layer. Also towards the left
hand cluster we have the volume and brightness control keys.

```text
| ~  | !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  |  DEL |
|     |MUTE|VOLD|VOLU|    |    |    |    | _  | +  | "  |     |
|      |BRUP|BRDN|    |    |    |    |    | {  |  } |PGUP| |  |
|    |    |    |    |          |        |      |HOME|PGDN|END |
```

## Fkeys (3)

I very rarely use Fkeys, but figured I'd throw them on anyway just in case. The setup basically mimics the way Fkeys are usually done on a 60%, with F11 and F12 still on - and =, even though the location of those keys has moved.

```text
|    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |      |
|     |    |    |    |    |    |    |    |    |F11 |F12 |     |
|      |    |    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |          |        |      |    |    |    |
```

## Mouse and LED Control Layer (4)

This layour has the mouse emulation along with LED control commands: toggle (G), decrease (H) and increase (J), and breathing mode toggle (K).

```text
|ESC |MRC|M_UP|MLCK|MWUP|    |    |    |    |    |    |       |
| TAB |M_LF|M_DN|M_RG|MWDN|LTOG|LDEC|LCINC|LBRT|    |    |     |
|      |    |    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |   SPACE  |        |      |    |    |    |
```
