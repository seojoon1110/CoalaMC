#include <CoalaMOD.h>
#include <stdio.h>
#pragma comment(lib, "CoalaMOD.lib")

int main() {

	WoodID oak = createWood(WOOD_OAK, STRIP_ALL_SIDE);
	BlockID light = createBlock(BLOCK_GLOWSTONE);
	BlockID empty = createBlock(BLOCK_AIR);
	BlockID glass = createBlock(BLOCK_GLASS);

	// 첫 번째 좌표 (sx,sy,sz)
	int sx, sy, sz;
	scanf_s("%d %d %d", &sx, &sy, &sz);

	// 두 번째 좌표 (ex,ey,ez)
	int ex, ey, ez;
	scanf_s("%d %d %d", &ex, &ey, &ez);

	// sx와 ex 중 큰 값을 ex, 작은 값을 sx로 반환
	int a;
	if (sx > ex) a = sx, sx = ex, ex = a;

	// sy와 ey 중 큰 값을 ey, 작은 값을 sy로 반환
	int b;
	if (sy > ey) b = sy, sy = ey, ey = b;

	// sz와 ez 중 큰 값을 ez, 작은 값을 sz로 반환
	int c;
	if (sz > ez) c = sz, sz = ez, ez = c;

	// 건물 벽 짓기
	int i, j;
	for (j = sy; j < ey; j++) {
		for (i = sx; i <= ex; i++) {
			locateWood(oak, i, j, sz);
			locateWood(oak, i, j, ez);
		}
	}

	int m, n;
	for (n = sy; n < ey; n++) {
		for (m = sz + 1; m < ez; m++) {
			locateWood(oak, sx, n, m);
			locateWood(oak, ex, n, m);
		}
	}

	// 지붕, 바닥 만들기
	int k, l;
	for (k = sx; k <= ex; k++) {
		for (l = sz; l <= ez; l++) {
			locateWood(oak, k, ey, l);
			locateWood(oak, k, sy, l);
		}
	}

	// 방 나누기
	int f, g, h, d, e;
	for (g = sy; g < ey; g++) {
		for (f = sx + 1; f < ex; f++) {
			locateWood(light, f, g, (sz + 2 * ez) / 3);
		}
		for (h = (sx + ex) / 2; h < ex; h++) {
			locateWood(light, h, g, (2 * sz + ez) / 3);
		}
		for (d = sz + 1; d < (2 * sz + ez) / 3; d++) {
			locateWood(light, (sx + ex) / 2, g, d);
		}
		for (e = (sz + 2 * ez) / 3 + 1; e < ez; e++) {
			locateWood(light, (sx + ex) / 2, g, e);
		}
	}

	// 내벽 발광석 처리
	int u, v;
	for (u = sx + 1; u < ex; u++) {
		for (v = sz + 1; v < ez; v++) {
			locateWood(light, u, sy + 1, v);
			locateWood(light, u, ey - 1, v);
		}
	}

	int dd, ee, ff;
	for (dd = sy + 1; dd < ey; dd++) {
		for (ee = sx + 1; ee < ex; ee++) {
			locateBlock(light, ee, dd, sz + 1);
			locateBlock(light, ee, dd, ez - 1);
		}
		for (ff = sz + 2; ff < ez - 1; ff++) {
			locateBlock(light, ex - 1, dd, ff);
			locateBlock(light, sx + 1, dd, ff);
		}
	}

	// 창문 만들기
	int qq, rr, ss, tt, uu, vv;
	for (qq = sy + 3; qq < ey - 3; qq = qq + 5) {
		for (rr = sx + 2; rr < ex - 2; rr = rr + 4) {
			locateBlock(glass, rr, qq, sz);
			locateBlock(glass, rr, qq, ez);
			locateBlock(glass, rr, qq, sz + 1);
			locateBlock(glass, rr, qq, ez - 1);
		}
		for (uu = sx + 3; uu < ex - 1; uu = uu + 4) {
			locateBlock(glass, uu, qq, sz);
			locateBlock(glass, uu, qq, ez);
			locateBlock(glass, uu, qq, sz + 1);
			locateBlock(glass, uu, qq, ez - 1);
		}
	}
	for (ss = sy + 4; ss < ey - 2; ss = ss + 5) {
		for (tt = sx + 2; tt < ex - 2; tt = tt + 4) {
			locateBlock(glass, tt, ss, sz);
			locateBlock(glass, tt, ss, ez);
			locateBlock(glass, tt, ss, sz + 1);
			locateBlock(glass, tt, ss, ez - 1);
		}
		for (vv = sx + 3; vv < ex - 1; vv = vv + 4) {
			locateBlock(glass, vv, ss, sz);
			locateBlock(glass, vv, ss, ez);
			locateBlock(glass, vv, ss, sz + 1);
			locateBlock(glass, vv, ss, ez - 1);
		}
	}
	
	int hh, ii, jj, kk, ll, mm;
	for (hh = sy + 3; hh < ey - 3; hh = hh + 5) {
		for (ii = sz + 2; ii < ez - 2; ii = ii + 4) {
			locateBlock(glass, sx, hh, ii);
			locateBlock(glass, ex, hh, ii);
			locateBlock(glass, sx + 1, hh, ii);
			locateBlock(glass, ex - 1, hh, ii);
		}
		for (jj = sz + 3; jj < ez - 1; jj = jj + 4) {
			locateBlock(glass, sx, hh, jj);
			locateBlock(glass, ex, hh, jj);
			locateBlock(glass, sx + 1, hh, jj);
			locateBlock(glass, ex - 1, hh, jj);
		}
		for (kk = sy + 4; kk < ey - 2; kk = kk + 5) {
			for (ll = sz + 2; ll < ez - 2; ll = ll + 4) {
				locateBlock(glass, sx, kk, ll);
				locateBlock(glass, ex, kk, ll);
				locateBlock(glass, sx + 1, kk, ll);
				locateBlock(glass, ex - 1, kk, ll);
			}
			for (mm = sz + 3; mm < ez - 1; mm = mm + 4) {
				locateBlock(glass, sx, kk, mm);
				locateBlock(glass, ex, kk, mm);
				locateBlock(glass, sx + 1, kk, mm);
				locateBlock(glass, ex - 1, kk, mm);
			}
		}
	}

	// 문 만들기
	int aa, bb, cc;
	for (aa = sy + 2; aa <= (2 * sy + ey) / 3; aa++) {
		for (cc = ex - 2; cc >= ex - 4; cc--) {
			locateBlock(empty, cc, aa, (sz + 2 * ez) / 3);
			locateBlock(empty, cc, aa, (sz + 2 * ez) / 3 + 1);
			locateBlock(empty, cc, aa, (sz + 2 * ez) / 3 - 1);
			locateBlock(empty, cc, aa, (2 * sz + ez) / 3);
			locateBlock(empty, cc, aa, (2 * sz + ez) / 3 + 1);
			locateBlock(empty, cc, aa, (2 * sz + ez) / 3 - 1);
		}
	}
	int xx, yy, zz, ww;
	for (xx = sx + 2; xx <= sx + 7; xx++) {
		for (yy = sy + 2; yy <= (2 * sy + ey) / 3; yy++) {
			locateBlock(oak, xx, yy, sx);
			locateBlock(light, xx, yy, sx + 1);
		}
	}
	for (zz = sy + 2; zz <= (2 * sy + ey) / 3; zz++) {
		for (ww = sx + 2; ww <= sx + 4; ww++) {
			locateBlock(empty, ww, zz, sz);
			locateBlock(empty, ww, zz, sz + 1);
			locateBlock(empty, ww, zz, (sz + 2 * ez) / 3);
		}
	}

	locateBlock(empty, sx + 2, sy + 1, sz);
	locateBlock(empty, sx + 3, sy + 1, sz);
	locateBlock(empty, sx + 4, sy + 1, sz);
}