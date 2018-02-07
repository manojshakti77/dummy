#include<stdio.h>

#define	START	1

void musicstart(void);
void musicstop(void);
void incomingcall(void);

#define EVENT_TABLE \
X(MUSIC_START)     Y(musicstart),\
X(MUSIC_STOP)      Y(musicstop),\
X(INCOMING_CALL)   Y(incomingcall)\

enum e { 
#define X(a) a
#define Y(a)
EVENT_TABLE
#undef X
#undef Y
};

static void(*actionptr[])(void ) = { 
#define Y(a) a
#define X(a)
EVENT_TABLE
#undef X
#undef Y
};

int main(void)
{
	/* If MUSIC_START event received */
	actionptr[MUSIC_START]();

	/* If MUSIC_START event received */
	actionptr[MUSIC_STOP]();


	/* If MUSIC_START event received */
	actionptr[INCOMING_CALL]();

	return 0;
}

void musicstart(void)
{
	printf("Music Start Action\n");	
}

void musicstop(void)
{
	printf("Music Stop Action\n");	
}

void incomingcall(void)
{
	printf("Incoming Call Action\n");
}	
