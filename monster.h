int multiple;
int level;
void monster(int code) {
	extern int multiple;
	extern int level;
	switch(code) {
	// 주인공
	case 0: setUsr(0, 0);  break; // 도적
	case 1: setUsr(1, 1);  break; // 전사
	case 2: setUsr(2, 2);  break; // 마법사
	case 3: setUsr(3, 3);  break; // 궁수
	case 4: setUsr(4, 4);  break; // 닌자
	case 5: setUsr(5, 5);  break; // 듀얼블레이드
	case 6: setUsr(2, 6);  break; // 마법사 진화형
	// 파트너
	case 7: setHero(0, 6, 7); break; // 섀도우 캣
	case 8: setHero(0,7,8); break; // 파이로
	case 9: setHero(0,8,9); break; // 아이스맨
	case 10: setHero(0,9,10); break; // 콜로서스
	case 11: setHero(0,10,11); break; // 로그
	// 몬스터
	case 12: setEnemy(multiple, level, 11, 12); // 하얀달팽이
	}
}
void name(int code) {
	extern char Name[];
	switch(code) {
	case 12: strcpy(Name, "하얀달팽이"); break;
	}
}
