/* See LICENSE file for copyright and license details. */

/* appearance */
#define BARPOS			BarTop /* BarBot, BarOff */
#define BORDERPX		1
#define FLOATBORDERPX		1
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
	{ "Gimp",			True,		0 },
	{ "MPlayer",			True,		0 },
	{ "Acroread",			True,		0 },
	{ "[Aa]udacious",		True,		0 },
	{ "gkrellm",			True,		0 },
	{ "pidgin",			True,		0 },	
	{ "[Xx]pdf",			True,		0 },	
};
#define INITIALWORKSPACES	 1
#define MAXWORKSPACES		99
#define MAXWSTEXTWIDTH		 6	/* must be 2*(strlen(MAXWORKSPACES)+1)  */
#define MAXXINERAMASCREENS	 2

/* ugly: depending on constants above but needed by layouts below */
double mwfact[MAXXINERAMASCREENS][MAXWORKSPACES];

/* layout(s) */
#define MWFACT			0.6	/* master width factor [0.1 .. 0.9] */
#define RESIZEHINTS		True	/* False - respect size hints in tiled resizals */
#define SNAP			32	/* snap pixel */
#include "bstack.c"
#include "maximize.c"
Layout layouts[] = {
	/* symbol		function || first entry is default */
	{ "TTT",		bstack },
	{ "[]=",		tile },
	{ "[ ]",		maximize },
	{ "<><",		floating }, 
};

/* key definitions */
#define MODKEY			Mod1Mask
/*#define SUPERKEY			Sup1Mask*/
Key keys[] = {
	/* modifier			key		function	argument */
	{ MODKEY,			XK_t,		spawn,		"exec x-terminal-emulator" },
	{ MODKEY,			XK_r ,		spawn,		"exec urxvt" },
	{ MODKEY|ShiftMask,		XK_y,		spawn,		"exec dwm-choose" },
	{ MODKEY,			XK_Tab,		focusnext,	NULL },
	{ MODKEY|ShiftMask,		XK_Tab,		focusprev,	NULL },
	{ MODKEY,			XK_Return,	zoom,		NULL },
	{ MODKEY,			XK_b,		togglebar,	NULL },
	{ MODKEY,			XK_j,		focusnext,	NULL },
	{ MODKEY,			XK_k,		focusprev,	NULL },
	{ MODKEY|ControlMask,		XK_e,		setmwfact,	"+0.05" },
	{ MODKEY|ControlMask,		XK_d,		setmwfact,	"-0.05" },
/*	{ MODKEY|ShiftMask,		XK_e,		incnmaster,	"1" }, */
/*	{ MODKEY|ShiftMask,		XK_d,		incnmaster,	"-1" }, */
	{ MODKEY|ShiftMask,		XK_a,		popstack,	NULL },
	{ MODKEY|ShiftMask,		XK_d,		pushstack,	NULL },
	{ MODKEY|ControlMask,		XK_y,		wscount,	"1" },
	{ MODKEY|ControlMask,		XK_x,		wscount,	"-1" },
	{ MODKEY|ControlMask,		XK_c,		killclient,	NULL },
	{ MODKEY|ShiftMask,		XK_f,		togglefloating,	NULL },
	{ MODKEY,			XK_f,		viewrel,	"1" },
	{ MODKEY,			XK_s,		viewrel,	"-1" },
	{ MODKEY|ControlMask,           XK_f,           warpmouserel,   "1" },
	{ MODKEY|ControlMask,           XK_s,           warpmouserel,   "-1" },
	{ MODKEY|ShiftMask|ControlMask,	XK_q,		quit,		NULL },
	{ MODKEY|ShiftMask,		XK_1,		setlayout,	"TTT" },
	{ MODKEY|ShiftMask,		XK_2,		setlayout,	"[]=" },
	{ MODKEY|ShiftMask,		XK_3,		setlayout,	"<><" },
	{ MODKEY|ShiftMask,		XK_4,		setlayout,	"[ ]" },
	{ MODKEY|ShiftMask,		XK_5,		setlayout,	"(@)" },
	{ MODKEY|ShiftMask,		XK_6,		setlayout,	"[\\]" },
	/*	defining some global public private shortcuts	*/
	{ MODKEY,			XK_Up,		spawn, 		"exec /home/andy/scripte/osd_volume.sh +"},
	{ MODKEY,			XK_Down,	spawn, 		"exec /home/andy/scripte/osd_volume.sh -"},
	{ MODKEY,			XK_Next,	spawn, 		"exec /home/andy/scripte/soundplayer next"},
	{ MODKEY,			XK_Prior,	spawn, 		"exec /home/andy/scripte/soundplayer previous"},
	{ MODKEY,			XK_Insert,	spawn, 		"exec /home/andy/scripte/soundplayer play"},
	{ MODKEY,			XK_Home,	spawn, 		"exec /home/andy/scripte/soundplayer pause"},
	{ MODKEY,			XK_End,		spawn, 		"exec /home/andy/scripte/soundplayer stop"},
	{ MODKEY|ControlMask,		XK_Return,	spawn, 		"exec xlock -mode blank"},
};
