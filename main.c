#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "design.h"
#include "info.h"
#include "monster.h"
#include "skill.h"
#include "job.h"
#include "quest.h"
#include "game.h"
#include "data.h"

int main() {
	setconsole();
	blank(9); drawline('@', 38); enter();
	blank(23); puts("W.A.R.ING.");
	blank (9); drawline('@', 38); enter();
	data_load();
	mission(0);
	mission(1);
	data_save();
	system("pause");
	return 0;
}
void setup() {
	int sel;
	enter();
	blank(9); drawline('@', 38); enter();
	blank(23); puts("Setup");
	blank (9); drawline('@', 38); enter();
	enter();
	blank(9); puts("게임에서 사용될 닉네임을 입력해주세요.");
	blank(9); printf(":"); scanf("%s", Usr.name);
	enter();
	blank(9); printf(" %s님이 원하시는 직업을 고르세요.\n");
	enter();
	blank(9); puts("[01] 도적");
	blank(9); puts("[특징] 표창을 주무기로 하는 직업");
	enter();
	blank(9); puts("[02] 전사");
	blank(9); puts("[특징] 위기의 순간 희생정신을 보여준다.");
	enter();
	blank(9); puts("[03] 마법사");
	blank(9); puts("[특징] 토큰을 만들어 적의 공격을 막아낸다.");
	enter();
	blank(9); drawline('@', 38); enter();
	blank(9); printf(":"); scanf("%d", &sel);
	switch(sel) {
	case 1: monster(0); break;
	case 2: monster(1); break;
	case 3: monster(2); break;
	}
}
