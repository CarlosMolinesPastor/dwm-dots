/* See LICENSE file for copyright and license details. */

/* ============================================================
 *  TECLAS Fx (códigos keysym para usar en atajos)
 * ============================================================ */
#define F1 0xffbe
#define F2 0xffbf
#define F3 0xffc0
#define F4 0xffc1
#define F5 0xffc2

/* ============================================================
 *  APARIENCIA
 * ============================================================ */
static const unsigned int borderpx       = 0;   /* grosor del borde de las ventanas (0 = sin borde) */
static const unsigned int default_border = 0;   /* borde por defecto al restaurar con atajo */
static const unsigned int snap           = 32;  /* píxeles de "snap" al mover ventanas flotantes */
static const unsigned int gappih         = 10;  /* hueco interno horizontal entre ventanas */
static const unsigned int gappiv         = 10;  /* hueco interno vertical entre ventanas */
static const unsigned int gappoh         = 10;  /* hueco externo horizontal (borde pantalla) */
static const unsigned int gappov         = 10;  /* hueco externo vertical (borde pantalla) */
static       int smartgaps               = 0;   /* 1 = sin huecos externos si solo hay 1 ventana */
static const unsigned int systraypinning = 0;   /* 0 = systray sigue al monitor activo; >0 = fija a monitor X */
static const unsigned int systrayspacing = 2;   /* espaciado entre iconos del systray */
static const int systraypinningfailfirst = 1;   /* 1 = si falla el pin, mostrar en el 1er monitor */
static const int showsystray             = 1;   /* 0 = ocultar systray */
static const int showbar                 = 1;   /* 0 = ocultar barra superior */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always };
static const int showtab                 = showtab_auto; /* modo de las pestañas */
static const int toptab                  = True;         /* pestañas arriba */
static const int topbar                  = 1;            /* 1 = barra arriba, 0 = abajo */
static const int horizpadbar             = 5;            /* padding horizontal de la barra */
static const int vertpadbar              = 11;           /* padding vertical de la barra */
static const int vertpadtab              = 33;           /* padding vertical de las pestañas */
static const int horizpadtabi            = 15;           /* padding horiz. interno de pestañas */
static const int horizpadtabo            = 15;           /* padding horiz. externo de pestañas */
static const int scalepreview            = 4;            /* escala de la vista previa de tags */
static       int tag_preview             = 1;            /* 1 = activar vista previa de tags */

/* Fuentes usadas por dwm */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style:medium:size=10",
                                        "Material Design Icons-Regular:size=10",
                                      };
/* Fuente usada por dmenu */
static const char dmenufont[]       = "NotoSans Nerd Font:style=Medium:size=8";
static const int colorfultag        = 1;  /* 0 = usar SchemeSel para tag no vacío */

/* Tema (incluye variables de color) */
#include "themes/catppuccin.h"

/* ============================================================
 *  ESQUEMAS DE COLOR
 *  Cada entrada tiene: { color_texto, color_fondo, color_borde }
 * ============================================================ */
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm]       = { gray3, black, gray2 },   /* ventana normal */
    [SchemeSel]        = { gray4, blue,  blue  },   /* ventana seleccionada */
    [TabSel]           = { blue, gray2,  black  },  /* pestaña seleccionada */
    [TabNorm]          = { gray3, black, black },   /* pestaña normal */
    [SchemeTag]        = { gray3, black, black },   /* etiqueta normal */
    [SchemeTag1]       = { blue,  black, black },   /* etiqueta 1 */
    [SchemeTag2]       = { red,   black, black },   /* etiqueta 2 */
    [SchemeTag3]       = { orange, black,black },   /* etiqueta 3 */
    [SchemeTag4]       = { green, black, black },   /* etiqueta 4 */
    [SchemeTag5]       = { pink,  black, black },   /* etiqueta 5 */
    [SchemeLayout]     = { green, black, black },   /* símbolo de layout */
    [SchemeBtnPrev]    = { green, black, black },   /* botón "anterior" */
    [SchemeBtnNext]    = { yellow, black, black },  /* botón "siguiente" */
    [SchemeBtnClose]   = { red, black, black },     /* botón "cerrar" */
};

/* ============================================================
 *  ETIQUETAS (TAGS)
 *  Iconos Nerd Font que aparecen en la barra superior
 * ============================================================ */
static char *tags[] = {"󰇩", "󰉋", "󰆍", "󰎞", "󰎄"};

/* Esquema de color asociado a cada etiqueta */
static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5,
                                };

static const unsigned int ulinepad      = 5;  /* padding horizontal de la línea inferior */
static const unsigned int ulinestroke   = 2;  /* grosor de la línea inferior */
static const unsigned int ulinevoffset  = 0;  /* altura de la línea respecto al fondo */
static const int ulineall               = 0;  /* 1 = subrayar todas las tags, 0 = solo la activa */

/* ============================================================
 *  REGLAS DE VENTANAS
 *  class      instance  title  tags mask  iscentered  isfloating  monitor
 *  (la máscara de tags 1<<N corresponde a la etiqueta N+1)
 * ============================================================ */
static const Rule rules[] = {
    { "Gimp",     NULL, NULL, 0,       0, 1, -1 },  /* Gimp siempre flotante */
    { "Firefox",  NULL, NULL, 1 << 8,  0, 0, -1 },  /* Firefox en etiqueta 9 */
    { "Viewnior", NULL, NULL, 0,       0, 1, -1 },  /* Viewnior flotante */
    { "eww",      NULL, NULL, 0,       0, 1, -1 },  /* eww (widgets) flotante */
    { "st",       NULL, NULL, 0,       0, 0, -1 },  /* st en layout normal */
};

/* ============================================================
 *  LAYOUTS
 * ============================================================ */
static const float mfact     = 0.50; /* factor del área master [0.05..0.95] */
static const int nmaster     = 1;    /* nº de ventanas en el área master */
static const int resizehints = 0;    /* 1 = respetar hints de tamaño al redimensionar */
static const int lockfullscreen = 1; /* 1 = mantener foco en ventana fullscreen */

#define FORCE_VSPLIT 1  /* nrowgrid: forzar división vertical con 2 clientes */
#include "functions.h"

/* Lista de layouts disponibles (el primero es el por defecto) */
static const Layout layouts[] = {
    /* símbolo   función de organización */
    { "[]=",      tile },                    /* [0]  tile (mosaico) */
    { "[M]",      monocle },                 /* [1]  monocle (una ventana a pantalla completa) */
    { "[@]",      spiral },                  /* [2]  spiral */
    { "[\\]",     dwindle },                 /* [3]  dwindle */
    { "H[]",      deck },                    /* [4]  deck */
    { "TTT",      bstack },                  /* [5]  bstack */
    { "===",      bstackhoriz },             /* [6]  bstack horizontal */
    { "HHH",      grid },                    /* [7]  grid */
    { "###",      nrowgrid },                /* [8]  nrowgrid */
    { "---",      horizgrid },               /* [9]  horizgrid */
    { ":::",      gaplessgrid },             /* [10] gaplessgrid */
    { "|M|",      centeredmaster },          /* [11] centeredmaster */
    { ">M>",      centeredfloatingmaster },  /* [12] centeredfloatingmaster */
    { "><>",      NULL },                    /* [13] flotante (sin layout) */
};

/* ============================================================
 *  DEFINICIÓN DE TECLAS
 * ============================================================ */
#define MODKEY Mod4Mask   /* Tecla Super/Windows como modificador principal */

/* Macro para generar los 4 atajos de cada etiqueta:
 *   Super+N            -> ver etiqueta N
 *   Super+Ctrl+N       -> alternar vista de etiqueta N
 *   Super+Shift+N      -> mover ventana a etiqueta N
 *   Super+Ctrl+Shift+N -> alternar etiqueta en ventana
 */
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

/* Helper para lanzar comandos de shell */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c" , cmd, NULL } }

/* ============================================================
 *  COMANDOS EXTERNOS
 * ============================================================ */
static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };  /* terminal: st (simple, ligero, rápido) */

/* ============================================================
 *  ATAJOS DE TECLADO
 * ============================================================ */
static Key keys[] = {
    /* modifier                  key        function        argument */

    /* ---------- TERMINAL Y LANZADORES ---------- */
    { MODKEY,                    XK_t,      spawn,          {.v = termcmd }},                            /* Super+t -> abrir terminal (st) */
    { MODKEY,                    XK_e,      spawn,          SHCMD("thunar")},                           /* Super+e -> abrir Thunar */
    { MODKEY,                    XK_b,      spawn,          SHCMD("firefox")},                          /* Super+b -> abrir Firefox */
    { MODKEY,                    XK_c,      spawn,          SHCMD("rofi -show drun")},                   /* Super+c -> rofi drun */
    { MODKEY,                    XK_a,      spawn,          SHCMD("~/.config/rofi/scripts/appsmenu.sh")}, /* Super+a -> menú de apps */
    { MODKEY,                    XK_r,      spawn,          SHCMD("~/.config/rofi/scripts/appsmenu.sh")}, /* Super+r -> menú de apps (alias) */
    { MODKEY,                    XK_o,      spawn,          SHCMD("rofi -show emoji -modi emoji")},       /* Super+o -> selector emoji */

    /* ---------- REDES (Gazelle TUI) ---------- */
    { MODKEY,                    XK_n,      spawn,          SHCMD("st -e gazelle")},                      /* Super+n -> gestor de redes Gazelle TUI */

    /* ---------- ROFI: POWERMENU Y VOLUMEN ---------- */
    { MODKEY,                    XK_x,      spawn,          SHCMD("~/.config/rofi/scripts/powermenu.sh")}, /* Super+x -> powermenu */
    { MODKEY,                    XK_v,      spawn,          SHCMD("~/.config/rofi/scripts/volume.sh")},    /* Super+v -> control volumen */
    { MODKEY,                    XK_p,      spawn,          SHCMD("~/.scripts/monitor")},                 /* Super+p -> script monitores */

    /* ---------- PICOM (compositor) ---------- */
    { MODKEY|ShiftMask,            XK_a,    spawn,          SHCMD("picom")},                              /* Super+Shift+a -> iniciar picom */
    { MODKEY|ControlMask|ShiftMask, XK_a,   spawn,          SHCMD("pkill -9 picom")},                     /* Super+Ctrl+Shift+a -> matar picom */

    /* ---------- YTFZF (YouTube desde terminal) ---------- */
    { MODKEY,                    XK_y,      spawn,          SHCMD("st -e youtube")},                      /* Super+y -> lanzar youtube en st */
    { MODKEY|ShiftMask,          XK_y,      spawn,          SHCMD("pkill -9 mpv")},                       /* Super+Shift+y -> cerrar mpv */

    /* ---------- CAPTURAS DE PANTALLA ---------- */
    { 0,                         XK_Print,  spawn,          SHCMD("~/.config/rofi/scripts/screenshot.sh")}, /* ImprPant -> captura */

    /* ---------- TECLAS Fx ---------- */
    { MODKEY,                    F1,        view,           {0} },                                          /* Super+F1 -> ver todas las tags */
    { MODKEY,                    F2,        restorewin,     {0} },                                          /* Super+F2 -> restaurar ventana oculta */
    { MODKEY,                    F3,        hidewin,        {0} },                                          /* Super+F3 -> ocultar ventana */
    { MODKEY,                    F4,        spawn,          SHCMD("~/.scripts/notify/change-volume up")},   /* Super+F4 -> subir volumen */
    { MODKEY,                    F5,        spawn,          SHCMD("~/.scripts/notify/change-volume down")}, /* Super+F5 -> bajar volumen */

    /* ---------- BARRA Y PESTAÑAS ---------- */
    { MODKEY,                    XK_w,      togglebar,      {0} },                    /* Super+w -> mostrar/ocultar barra */
    { MODKEY|ControlMask,        XK_w,      tabmode,        { -1 } },                 /* Super+Ctrl+w -> cambiar modo pestañas */

    /* ---------- NAVEGACIÓN ENTRE VENTANAS ---------- */
    { MODKEY,                    XK_j,      focusstack,     {.i = +1 } },             /* Super+j -> foco a ventana siguiente */
    { MODKEY,                    XK_k,      focusstack,     {.i = -1 } },             /* Super+k -> foco a ventana anterior */
    { MODKEY|ShiftMask,          XK_j,      movestack,      {.i = +1 } },             /* Super+Shift+j -> mover ventana abajo en el stack */
    { MODKEY|ShiftMask,          XK_k,      movestack,      {.i = -1 } },             /* Super+Shift+k -> mover ventana arriba en el stack */
    { MODKEY,                    XK_Tab,    view,           {0} },                    /* Super+Tab -> volver a la etiqueta anterior */
    { MODKEY|ControlMask,        XK_Return, zoom,           {0} },                    /* Super+Ctrl+Enter -> zoom (ventana a master) */

    /* ---------- MASTER: Nº VENTANAS Y FACTORES ---------- */
    { MODKEY,                    XK_i,      incnmaster,     {.i = +1 } },             /* Super+i -> +1 ventana en master */
    { MODKEY,                    XK_d,      incnmaster,     {.i = -1 } },             /* Super+d -> -1 ventana en master */
    { MODKEY,                    XK_h,      setmfact,       {.f = -0.05} },           /* Super+h -> reducir factor master */
    { MODKEY,                    XK_l,      setmfact,       {.f = +0.05} },           /* Super+l -> aumentar factor master */
    { MODKEY|ShiftMask,          XK_h,      setcfact,       {.f = +0.25} },           /* Super+Shift+h -> +cfact */
    { MODKEY|ShiftMask,          XK_l,      setcfact,       {.f = -0.25} },           /* Super+Shift+l -> -cfact */
    { MODKEY|ShiftMask,          XK_o,      setcfact,       {.f =  0.00} },           /* Super+Shift+o -> resetear cfact */

    /* ---------- GAPS (HUECOS) ---------- */
    { MODKEY|ControlMask,        XK_i,      incrgaps,       {.i = +1 } },             /* Super+Ctrl+i -> +gaps globales */
    { MODKEY|ControlMask,        XK_d,      incrgaps,       {.i = -1 } },             /* Super+Ctrl+d -> -gaps globales */
    { MODKEY|ShiftMask,          XK_i,      incrigaps,      {.i = +1 } },             /* Super+Shift+i -> +gaps internos */
    { MODKEY|ControlMask|ShiftMask, XK_i,   incrigaps,      {.i = -1 } },             /* Super+Ctrl+Shift+i -> -gaps internos */
    { MODKEY|ControlMask,        XK_o,      incrogaps,      {.i = +1 } },             /* Super+Ctrl+o -> +gaps externos */
    { MODKEY|ControlMask|ShiftMask, XK_o,   incrogaps,      {.i = -1 } },             /* Super+Ctrl+Shift+o -> -gaps externos */
    { MODKEY|ControlMask,        XK_6,      incrihgaps,     {.i = +1 } },             /* Super+Ctrl+6 -> +gap interno horiz. */
    { MODKEY|ControlMask|ShiftMask, XK_6,   incrihgaps,     {.i = -1 } },             /* Super+Ctrl+Shift+6 -> -gap interno horiz. */
    { MODKEY|ControlMask,        XK_7,      incrivgaps,     {.i = +1 } },             /* Super+Ctrl+7 -> +gap interno vert. */
    { MODKEY|ControlMask|ShiftMask, XK_7,   incrivgaps,     {.i = -1 } },             /* Super+Ctrl+Shift+7 -> -gap interno vert. */
    { MODKEY|ControlMask,        XK_8,      incrohgaps,     {.i = +1 } },             /* Super+Ctrl+8 -> +gap externo horiz. */
    { MODKEY|ControlMask|ShiftMask, XK_8,   incrohgaps,     {.i = -1 } },             /* Super+Ctrl+Shift+8 -> -gap externo horiz. */
    { MODKEY|ControlMask,        XK_9,      incrovgaps,     {.i = +1 } },             /* Super+Ctrl+9 -> +gap externo vert. */
    { MODKEY|ControlMask|ShiftMask, XK_9,   incrovgaps,     {.i = -1 } },             /* Super+Ctrl+Shift+9 -> -gap externo vert. */
    { MODKEY|ControlMask,        XK_t,      togglegaps,     {0} },                    /* Super+Ctrl+t -> activar/desactivar gaps */
    { MODKEY|ControlMask|ShiftMask, XK_d,   defaultgaps,    {0} },                    /* Super+Ctrl+Shift+d -> gaps por defecto */

    /* ---------- GESTIÓN DE VENTANAS ---------- */
    { MODKEY,                    XK_q,      killclient,     {0} },                    /* Super+q -> cerrar ventana */
    { MODKEY|ShiftMask,          XK_space,  togglefloating, {0} },                    /* Super+Shift+space -> flotante on/off */
    { MODKEY,                    XK_m,      togglefullscr,  {0} },                    /* Super+m -> pantalla completa on/off */

    /* ---------- LAYOUTS ---------- */
    { MODKEY|ShiftMask,          XK_m,      setlayout,      {.v = &layouts[0]} },     /* Super+Shift+m -> layout tile */
    { MODKEY|ShiftMask,          XK_f,      setlayout,      {.v = &layouts[1]} },     /* Super+Shift+f -> layout monocle */
    { MODKEY,                    XK_s,      setlayout,      {.v = &layouts[2]} },     /* Super+s -> layout spiral */
    { MODKEY|ControlMask,        XK_g,      setlayout,      {.v = &layouts[10]} },    /* Super+Ctrl+g -> layout gaplessgrid */
    { MODKEY|ControlMask|ShiftMask, XK_t,   setlayout,      {.v = &layouts[13]} },    /* Super+Ctrl+Shift+t -> layout flotante */
    { MODKEY,                    XK_space,  setlayout,      {0} },                    /* Super+space -> alternar último layout */
    { MODKEY|ControlMask,        XK_comma,  cyclelayout,    {.i = -1 } },             /* Super+Ctrl+, -> layout anterior */
    { MODKEY|ControlMask,        XK_period, cyclelayout,    {.i = +1 } },             /* Super+Ctrl+. -> layout siguiente */

    /* ---------- ETIQUETAS GLOBALES / MONITORES ---------- */
    { MODKEY,                    XK_0,      view,           {.ui = ~0 } },            /* Super+0 -> ver todas las tags */
    { MODKEY|ShiftMask,          XK_0,      tag,            {.ui = ~0 } },            /* Super+Shift+0 -> mover ventana a todas las tags */
    { MODKEY,                    XK_comma,  focusmon,       {.i = -1 } },             /* Super+, -> monitor anterior */
    { MODKEY,                    XK_period, focusmon,       {.i = +1 } },             /* Super+. -> monitor siguiente */
    { MODKEY|ShiftMask,          XK_comma,  tagmon,         {.i = -1 } },             /* Super+Shift+, -> mover ventana a monitor anterior */
    { MODKEY|ShiftMask,          XK_period, tagmon,         {.i = +1 } },             /* Super+Shift+. -> mover ventana a monitor siguiente */

    /* ---------- BORDES ---------- */
    { MODKEY|ShiftMask,          XK_minus,  setborderpx,    {.i = -1 } },             /* Super+Shift+- -> reducir borde */
    { MODKEY|ShiftMask,          XK_p,      setborderpx,    {.i = +1 } },             /* Super+Shift+p -> aumentar borde */
    { MODKEY|ShiftMask,          XK_w,      setborderpx,    {.i = default_border } }, /* Super+Shift+w -> borde por defecto */

    /* ---------- ETIQUETAS 1-5 (generadas con la macro TAGKEYS) ---------- */
    TAGKEYS(                     XK_1,      0)   /* Super+1 -> etiqueta 1 */
    TAGKEYS(                     XK_2,      1)   /* Super+2 -> etiqueta 2 */
    TAGKEYS(                     XK_3,      2)   /* Super+3 -> etiqueta 3 */
    TAGKEYS(                     XK_4,      3)   /* Super+4 -> etiqueta 4 */
    TAGKEYS(                     XK_5,      4)   /* Super+5 -> etiqueta 5 */

    /* ---------- SALIR / REINICIAR DWM ---------- */
    { MODKEY|ControlMask,        XK_q,      quit,           {0} },   /* Super+Ctrl+q -> salir de dwm */
    { MODKEY|ShiftMask,          XK_r,      quit,           {1} },   /* Super+Shift+r -> reiniciar dwm */
};

/* ============================================================
 *  BOTONES DEL RATÓN
 * ============================================================ */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },

    { ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         ControlMask,    Button1,        dragmfact,      {0} },
    { ClkClientWin,         ControlMask,    Button3,        dragcfact,      {0} },

    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },

    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabPrev,           0,              Button1,        movestack,      { .i = -1 } },
    { ClkTabNext,           0,              Button1,        movestack,      { .i = +1 } },
    { ClkTabClose,          0,              Button1,        killclient,     {0} },
};
