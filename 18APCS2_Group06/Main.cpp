//Group: 06 (18APCS2)
/*Members: +Lam Duc Huy (ID: 18125131)
		   +Huynh Mac Khai (ID: 18125084)
		   +Le Tuan Khanh (ID: 18125087)*/
		   //Project: GOMOKU
#include"Function.h"


int main()
{
	char m1 = 88, m2 = 79, m3 = 127;
	int l = 19, w = 19, n = 100, b = 2, d = 2, w1 = 0, w2 = 0, w3 = 0, draw = 0, full = 0;
	bool cont = 1;
	system("Color 0B");

	cout << "            `/yyyyyyy+    :yhyyyyh+`   /mdh`      `hdm-   `+hyyyyhy:    hd   .yh:  sm`     -m+          \n";
	cout << "           -md:`   `.:   sN+.   `:Nd.  oMsNy     `hdsM:  .mm:`   .oMs   mN``+my.   hM`     :Ms          \n";
	cout << "           mN.   `````  :My       +Mo  oM//Mo    yN.oM:  yM:       dM.  mN:hd:     hM`     :Ms          \n";
	cout << "          `Mm   -yyymh  +Mo       :My  oM/ sM/  oN: oM:  dM`       yM:  mNsMs`     hM`     :Ms          \n";
	cout << "           dM-   ```Nm  :Mh       sM/  oM/ `hN-/N+  oM:  yM/      `mN`  mN`:md-    yM.     /Mo          \n";
	cout << "           .hNo-.``-Nm   oNy-.``-sNs   oM/  `mmNs   oM:  .dN+.``./dm:   mN  `sNs`  -Nd:``.:mm.          \n";
	cout << "             -oyyyyso:    -oyyyys+.    :h-   -hs`   /h-   `:syyyys/`    sy    :yo   .+yyyys/`           \n\n";
	cout << "                                  -- AN ABSTRACT STRATEGY BOARDGAME --                                 \n\n";
	cout << "                                    ==============Rule==============                                   \n";
	cout << "The winner is the first player to order an unbroken row of five signs HORIZONTALLY, VERTICALLY, or DIAGONALLY ! ! !.\n";

	system("pause");
	system("cls");
	menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
	return 0;
}