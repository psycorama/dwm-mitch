/* See LICENSE file for copyright and license details. */

/* appearance */
#define BARPOS			BarTop /* BarBot, BarOff */
#define BORDERPX		1
#define FLOATBORDERPX		0
#define FONT			"-misc-fixed-medium-r-normal-*-13-*-*-*-*-*-*-*"
#define NORMBORDERCOLOR		"#080"
#define NORMBGCOLOR		"#222"
#define NORMFGCOLOR		"#0c0"
#define SELBORDERCOLOR		"#9cf"
#define SELBGCOLOR		"#555"
#define SELFGCOLOR		"#080"

/* workspaces */
/* Query class:instance:title for regex matching info with following command:
 * xprop | awk -F '"' '/^WM_CLASS/ { printf("%s:%s:",$4,$2) }; /^WM_NAME/ { printf("%s\n",$2) }' */
Rule rules[] = {
	/* class:instance:title regex	isfloating	workspace (0=current)*/
	{ "Firefox",			False,		0 },
	{ "[Mm][Pp]layer",		True,		0 },
	{ "[Mm][Pp]layer2",		True,		0 },
	{ "Vlc",			True,		0 },
	{ "Xine",			True,		0 },
	{ "Audacious",			True,		0 },
	{ "pidgin",			True,		0 },	
};
#define INITIALWORKSPACES	 3
#define MAXWORKSPACES		99
#define MAXWSTEXTWIDTH		 6	/* must be 2*(strlen(MAXWORKSPACES)+1)  */
#define MAXXINERAMASCREENS	 2

/* volume management via status bar - undefine VOLUME to deactivate */
#define VOLUME
int vw = 16; /* pixels from the right to activate volume management on bar */
const char *volup   = "amixer set Master 5%+";
const char *voldown = "amixer set Master 5%-";

/* ugly: depending on constants above but needed by layouts below */
double mwfact[MAXXINERAMASCREENS][MAXWORKSPACES];
Bool domwfact[MAXXINERAMASCREENS] = {True};
Bool dozoom[MAXXINERAMASCREENS] = {True};

/* layout(s) */
#define MWFACT			0.6	/* master width factor [0.1 .. 0.9] */
#define RESIZEHINTS		True	/* False - respect size hints in tiled resizals */
#define SNAP			16	/* snap pixel */
#include "bstack.c"
#include "maximize.c"
#include "widescreen.c"
Layout layouts[] = {
	/* symbol		function || first entry is default */
	{ "TTT",		bstack },
	{ "[]=",		tile },
	{ "= =",		widescreen },
	{ "[ ]",		maximize },
	{ "<><",		floating }, 
};

/* key definitions */
#define MODKEY			Mod1Mask
/*#define SUPERKEY			Sup1Mask*/
Key keys[] = {
	/* modifier			key		function	argument */
	{ MODKEY|ShiftMask,		XK_u,		spawn,		"exec x-terminal-emulator" },
	{ MODKEY,			XK_u ,		spawn,		"exec urxvt" },
	{ MODKEY|ShiftMask,		XK_p,		spawn,		"exec dwm-choose" },
	{ MODKEY,			XK_Tab,		focusnext,	NULL },
	{ MODKEY|ShiftMask,		XK_Tab,		focusprev,	NULL },
	{ MODKEY,			XK_Return,	zoom,		NULL },
	{ MODKEY,			XK_b,		togglebar,	NULL },
	{ MODKEY,			XK_n,		focusnext,	NULL },
	{ MODKEY,			XK_p,		focusprev,	NULL },
	{ MODKEY|ControlMask,		XK_u,		setmwfact,	"+0.05" },
	{ MODKEY|ControlMask,		XK_i,		setmwfact,	"-0.05" },
	{ MODKEY|ShiftMask,		XK_s,		swapscreen,	"1" },
	{ MODKEY|ControlMask,		XK_1,		view,		"1" },
	{ MODKEY|ControlMask,		XK_2,		view,		"2" },
	{ MODKEY|ControlMask,		XK_3,		view,		"3" },
	{ MODKEY|ControlMask,		XK_4,		view,		"4" },
	{ MODKEY|ControlMask,		XK_5,		view,		"5" },
	{ MODKEY|ControlMask,		XK_6,		view,		"6" },
	{ MODKEY|ControlMask,		XK_7,		view,		"7" },
	{ MODKEY|ControlMask,		XK_8,		view,		"8" },
	{ MODKEY|ControlMask,		XK_9,		view,		"9" },
	{ MODKEY|ControlMask,		XK_0,		view,		"10" },
	{ MODKEY|ControlMask|ShiftMask,	XK_1,		moveto,		"1" },
	{ MODKEY|ControlMask|ShiftMask,	XK_2,		moveto,		"2" },
	{ MODKEY|ControlMask|ShiftMask,	XK_3,		moveto,		"3" },
	{ MODKEY|ControlMask|ShiftMask,	XK_4,		moveto,		"4" },
	{ MODKEY|ControlMask|ShiftMask,	XK_5,		moveto,		"5" },
	{ MODKEY|ControlMask|ShiftMask,	XK_6,		moveto,		"6" },
	{ MODKEY|ControlMask|ShiftMask,	XK_7,		moveto,		"7" },
	{ MODKEY|ControlMask|ShiftMask,	XK_8,		moveto,		"8" },
	{ MODKEY|ControlMask|ShiftMask,	XK_9,		moveto,		"9" },
	{ MODKEY|ControlMask|ShiftMask,	XK_0,		moveto,		"10" },
	{ MODKEY|ShiftMask,		XK_c,		popstack,	NULL },
	{ MODKEY|ShiftMask,		XK_i,		pushstack,	NULL },
	{ MODKEY|ControlMask,		XK_n,		wscount,	"1" },
	{ MODKEY|ControlMask|ShiftMask,	XK_n,		wscount,	"-1" },
	{ MODKEY|ControlMask|ShiftMask,	XK_k,		killclient,	NULL },
	{ MODKEY|ShiftMask,		XK_f,		togglefloating,	NULL },
	{ MODKEY,			XK_e,		viewrel,	"1" },
	{ MODKEY,			XK_t,		viewrel,	"-1" },
	{ MODKEY,			XK_o,           warpmouserel,   "1" },
	{ MODKEY|ShiftMask,		XK_o,           warpmouserel,   "-1" },
	{ MODKEY|ShiftMask|ControlMask,	XK_q,		quit,		NULL },
	{ MODKEY|ShiftMask,		XK_1,		setlayout,	"TTT" },
	{ MODKEY|ShiftMask,		XK_2,		setlayout,	"[]=" },
	{ MODKEY|ShiftMask,		XK_3,		setlayout,	"<><" },
	{ MODKEY|ShiftMask,		XK_4,		setlayout,	"[ ]" },
	{ MODKEY|ShiftMask,		XK_5,		setlayout,	"= =" },
	/*	defining some global public private shortcuts	*/
	{ MODKEY,			XK_Up,		spawn, 		"exec $HOME/scripte/osd_volume.sh +"},
	{ MODKEY,			XK_Down,	spawn, 		"exec $HOME/scripte/osd_volume.sh -"},
	{ MODKEY,			XK_Next,	spawn, 		"exec $HOME/scripte/soundplayer next"},
	{ MODKEY,			XK_Prior,	spawn, 		"exec $HOME/scripte/soundplayer previous"},
	{ MODKEY,			XK_Insert,	spawn, 		"exec $HOME/scripte/soundplayer play"},
	{ MODKEY,			XK_Home,	spawn, 		"exec $HOME/scripte/soundplayer pause"},
	{ MODKEY,			XK_End,		spawn, 		"exec $HOME/scripte/soundplayer stop"},
	{ MODKEY|ControlMask,		XK_Return,	spawn, 		"exec $HOME/scripte/lock_it.sh"},
	{ MODKEY|ShiftMask,		XK_F7,		spawn, 		"exec $HOME/scripte/keyboard_settings.sh starbound"},
	{ MODKEY|ShiftMask,		XK_F8,		spawn, 		"exec $HOME/scripte/keyboard_settings.sh"},
	{ MODKEY|ShiftMask,		XK_F9,		spawn, 		"exec $HOME/scripte/mm_v3.sh"},
};
