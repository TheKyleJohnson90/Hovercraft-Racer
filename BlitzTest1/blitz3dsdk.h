
#ifndef BLITZ3DSDK_H
#define BLITZ3DSDK_H

/*

C, C++ include file for the Blitz3d SDK.

Copyright Blitz Research Ltd. Please see license.txt for license details.

*/

#ifdef __cplusplus
extern "C"{
#endif

#define BBSDK_API __declspec(dllimport)

#define BBFALSE 0
#define BBTRUE 1

#define GFX_DEFAULT 0
#define GFX_FULLSCREEN 1
#define GFX_WINDOWED 2
#define GFX_WINDOWEDSCALED 3

#define PROJ_NONE 0
#define PROJ_PERSPECTIVE 1
#define PROJ_ORTHO 2

#define LIGHT_DIRECTIONAL 1
#define LIGHT_POINT 2
#define LIGHT_SPOT 3

#define TX_COLOR 1
#define TX_ALPHA 2
#define TX_MASKED 4
#define TX_MIP 8
#define TX_CLAMPU 16
#define TX_CLAMPV 32
#define TX_SPHERE 64
#define TX_CUBIC 128
#define TX_VRAM 256
#define TX_HIGHCOLOR 512

#define TX_BLEND_NONE 0
#define TX_BLEND_ALPHA 1
#define TX_BLEND_MULT 2
#define TX_BLEND_ADD 3
#define TX_BLEND_DOT3 4
#define TX_BLEND_MULT2 5

#define CUBEFACE_LEFT 0
#define CUBEFACE_FRONT 1
#define CUBEFACE_RIGHT 2
#define CUBEFACE_BACK 3
#define CUBEFACE_TOP 4
#define CUBEFACE_BOTTOM 5

#define CUBEMODE_SPECULAR 1
#define CUBEMODE_DIFFUSE 2
#define CUBEMODE_REFRACTION 3

#define BRUSHBLEND_NONE 0
#define BRUSHBLEND_MULTIPLY 1
#define BRUSHBLEND_ALPHA 2
#define BRUSHBLEND_ADD 3

#define BRUSHFX_NONE 0
#define BRUSHFX_FULLBRIGHT 1
#define BRUSHFX_VERTEXCOLOR 2
#define BRUSHFX_FLAT 4
#define BRUSHFX_NOFOG 8
#define BRUSHFX_DOUBLESIDED 16
#define BRUSHFX_VERTEXALPHA 32

#define COLLIDE_SPHERESPHERE 1
#define COLLIDE_SPHEREPOLY 2
#define COLLIDE_SPHEREBOX 3

#define COLLIDE_STOP 1
#define COLLIDE_SLIDE1 2
#define COLLIDE_SLIDE2 3

#define PICK_NONE 0
#define PICK_SPHERE 1
#define PICK_POLY 2
#define PICK_BOX 3

#define ANIM_STOP 0
#define ANIM_LOOP 1
#define ANIM_PINGPONG 2
#define ANIM_ONCE 3

#define SPRITE_TURNXY 1
#define SPRITE_STILL 2
#define SPRITE_ALIGNZ 3
#define SPRITE_TURNY 4

#define PLAYCD_SINGLE 1
#define PLAYCD_LOOP 2
#define PLAYCD_ALL 3

#define MOUSE_BUTTON 1
#define MOUSE_RIGHTBUTTON 2
#define MOUSE_MIDDLEBUTTON 3

#define JOYTYPE_NONE 0
#define JOYTYPE_DIGITAL 1 
#define JOYTYPE_ANALOG 2

#define KEY_ESCAPE 1
#define KEY_TAB 15
#define KEY_SPACE 57
#define KEY_RETURN 28
#define KEY_LEFTSHIFT 42
#define KEY_LEFTCONTROL 29
#define KEY_LEFTALT 56
#define KEY_RIGHTSHIFT 54
#define KEY_RIGHTCONTROL 157
#define KEY_RIGHTALT 184
 
#define KEY_UP 200
#define KEY_LEFT 203
#define KEY_RIGHT 205
#define KEY_DOWN 208
 
#define KEY_F1 59
#define KEY_F2 60 
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67
#define KEY_F10 68

#define KEY_Q 16
#define KEY_W 17
#define KEY_E 18
#define KEY_R 19
#define KEY_T 20 
#define KEY_Y 21
#define KEY_U 22
#define KEY_I 23
#define KEY_O 24
#define KEY_P 25
 
#define KEY_A 30 
#define KEY_S 31
#define KEY_D 32
#define KEY_F 33
#define KEY_G 34
#define KEY_H 35
#define KEY_J 36
#define KEY_K 37
#define KEY_L 38
 
#define KEY_Z 44
#define KEY_X 45
#define KEY_C 46
#define KEY_V 47
#define KEY_B 48
#define KEY_N 49
#define KEY_M 50 
 
#define KEY_1 2
#define KEY_2 3
#define KEY_3 4
#define KEY_4 5
#define KEY_5 6
#define KEY_6 7
#define KEY_7 8
#define KEY_8 9
#define KEY_9 10 
#define KEY_0 11

#define KEY_MINUS 12
#define KEY_EQUALS 13
#define KEY_BACKSPACE 14
#define KEY_LEFTBRACKET 26
#define KEY_RIGHTBRACKET 27
#define KEY_SEMICOLON 39
#define KEY_APOSTROPHE 40 
#define KEY_GRAVE 41
#define KEY_BACKSLASH 43
#define KEY_COMMA 51
#define KEY_PERIOD 52
#define KEY_SLASH 53
#define KEY_CAPSLOCK 58
 
#define KEY_PRINT 183
#define KEY_SCROLLLOCK 70 
#define KEY_PAUSEBREAK 197
#define KEY_INSERT 210
#define KEY_DELETE 211
#define KEY_HOME 199
#define KEY_END 207
#define KEY_PAGEUP 201
#define KEY_PAGEDOWN 209

#define KEY_NUMLOCK 69
#define KEY_NUMPADDIVIDE 181
#define KEY_NUMPADMULT 55
#define KEY_NUMPADMINUS 74
#define KEY_NUMPADPLUS 78
#define KEY_NUMPADENTER 156
#define KEY_NUMPADDOT 83
#define KEY_NUMPAD0 82
#define KEY_NUMPAD1 79
#define KEY_NUMPAD2 80 
#define KEY_NUMPAD3 81
#define KEY_NUMPAD4 75
#define KEY_NUMPAD5 76
#define KEY_NUMPAD6 77
#define KEY_NUMPAD7 71
#define KEY_NUMPAD8 72
#define KEY_NUMPAD9 73

#define KEY_F11 87
#define KEY_F12 88
#define KEY_LEFTWINDOWS 219
#define KEY_RIGHTWINDOWS 220
#define KEY_NUMPADEQUALS 141
#define KEY_NUMPADCOMMA 179
#define KEY_OEM_102 86
#define KEY_AT 145
#define KEY_COLON 146
#define KEY_UNDERLINE 147
#define KEY_BREAK 149

#define KEY_PREVIOUSTRACK 144
#define KEY_NEXTTRACK 153
#define KEY_MUTE 160
#define KEY_PLAYPAUSE 162
#define KEY_STOP 164
#define KEY_VOLUMELESS 174
#define KEY_VOLUMEMORE 176
 
#define KEY_APPS 221
#define KEY_POWER 222
#define KEY_SLEEP 223
#define KEY_WAKE 227

#define KEY_WEBHOME 178
#define KEY_WEBSEARCH 229
#define KEY_WEBFAVORITES 230 
#define KEY_WEBREFRESH 231
#define KEY_WEBSTOP 232
#define KEY_WEBFORWARD 233
#define KEY_WEBBACK 234
 
#define KEY_MYCOMPUTER 235
#define KEY_CALCULATOR 161
#define KEY_MAIL 236
#define KEY_MEDIASELECT 237

//typedef void * BBObject;
typedef int BBObject;

typedef BBObject BBTimer;
typedef BBObject BBSound;
typedef BBObject BBChannel; 

typedef BBObject BBGraphics; 
typedef BBObject BBImage;
typedef BBObject BBMovie;
typedef BBObject BBFont;
typedef BBObject BBCanvas;
typedef BBObject BBScene;

typedef BBObject BBLight;
typedef BBObject BBCamera;
typedef BBObject BBModel;
typedef BBObject BBEntity;
typedef BBObject BBSurface;
typedef BBObject BBTexture;
typedef BBObject BBBrush;
typedef BBObject BBPivot;
typedef BBObject BBSprite;
typedef BBObject BBPlaneModel;
typedef BBObject BBMeshModel;
typedef BBObject BBQ3BSPModel;
typedef BBObject BBMD2Model;
typedef BBObject BBMirror;
typedef BBObject BBTerrain;

//bbruntime

BBSDK_API int bbVersion();

BBSDK_API void bbSetBlitz3DDebugMode(int debugmode);
BBSDK_API void bbSetBlitz3DDebugCallback(void (*callback)(const char *));
BBSDK_API void bbSetBlitz3DEventCallback(int (*callback)(int hwnd,int msg,int wparam,int lparam));
BBSDK_API void bbSetBlitz3DHWND(int hwndparent);
BBSDK_API void bbSetBlitz3DTitle(const char *title,const char *close);

BBSDK_API int bbBeginBlitz3D();
BBSDK_API void bbEndBlitz3D();

BBSDK_API void bbRuntimeError( const char * );

BBSDK_API int bbMilliSecs();

BBSDK_API void bbDelay( int ms );
BBSDK_API void bbShowPointer();
BBSDK_API void bbHidePointer();

BBSDK_API BBTimer bbCreateTimer( int hz );
BBSDK_API void bbFreeTimer(BBTimer timer);
BBSDK_API void bbWaitTimer(BBTimer timer);

// bbinput

//keyboard
BBSDK_API int bbKeyDown( int n );
BBSDK_API int bbKeyHit( int n );
BBSDK_API int bbGetKey();
BBSDK_API int bbWaitKey();
BBSDK_API void bbFlushKeys();

//mouse
BBSDK_API int bbMouseDown( int n );
BBSDK_API int bbMouseHit( int n );
BBSDK_API int bbGetMouse();
BBSDK_API int bbWaitMouse();
BBSDK_API int bbMouseX();
BBSDK_API int bbMouseY();
BBSDK_API int bbMouseZ();
BBSDK_API int bbMouseXSpeed();
BBSDK_API int bbMouseYSpeed();
BBSDK_API int bbMouseZSpeed();
BBSDK_API void bbMoveMouse( int x,int y );
BBSDK_API void bbFlushMouse();

//joysticks
#ifdef __cplusplus
BBSDK_API int bbJoyType( int port=0 );
BBSDK_API int bbJoyDown( int n,int port=0 );
BBSDK_API int bbJoyHit( int n,int port=0 );
BBSDK_API int bbGetJoy( int port=0 );
BBSDK_API int bbWaitJoy( int port=0 );
BBSDK_API float bbJoyX( int port=0 );
BBSDK_API float bbJoyY( int port=0 );
BBSDK_API float bbJoyZ( int port=0 );
BBSDK_API float bbJoyU( int port=0 );
BBSDK_API float bbJoyV( int port=0 );
BBSDK_API float bbJoyPitch( int port=0 );
BBSDK_API float bbJoyYaw( int port=0 );
BBSDK_API float bbJoyRoll( int port=0 );
BBSDK_API int bbJoyHat( int port=0 );
BBSDK_API int bbJoyXDir( int port=0 );
BBSDK_API int bbJoyYDir( int port=0 );
BBSDK_API int bbJoyZDir( int port=0 );
BBSDK_API int bbJoyUDir( int port=0 );
BBSDK_API int bbJoyVDir( int port=0 );
#else
BBSDK_API int bbJoyType( int port );
BBSDK_API int bbJoyDown( int n,int port );
BBSDK_API int bbJoyHit( int n,int port );
BBSDK_API int bbGetJoy( int port );
BBSDK_API int bbWaitJoy( int port );
BBSDK_API float bbJoyX( int port );
BBSDK_API float bbJoyY( int port );
BBSDK_API float bbJoyZ( int port );
BBSDK_API float bbJoyU( int port );
BBSDK_API float bbJoyV( int port );
BBSDK_API float bbJoyPitch( int port );
BBSDK_API float bbJoyYaw( int port );
BBSDK_API float bbJoyRoll( int port );
BBSDK_API int bbJoyHat( int port );
BBSDK_API int bbJoyXDir( int port );
BBSDK_API int bbJoyYDir( int port );
BBSDK_API int bbJoyZDir( int port );
BBSDK_API int bbJoyUDir( int port );
BBSDK_API int bbJoyVDir( int port );
#endif
BBSDK_API void bbFlushJoy();

// bbaudio

#ifdef __cplusplus
BBSDK_API BBSound bbLoadSound( const char *src,int flags=0 );
#else
BBSDK_API BBSound bbLoadSound( const char *src,int flags );
#endif
BBSDK_API void bbFreeSound( BBSound sound );
BBSDK_API BBChannel bbPlaySound( BBSound sound );
BBSDK_API void bbLoopSound( BBSound sound );
BBSDK_API void bbSoundPitch( BBSound sound,int pitch );
BBSDK_API void bbSoundVolume( BBSound sound,float volume );
BBSDK_API void bbSoundPan( BBSound sound,float pan );
#ifdef __cplusplus
BBSDK_API BBChannel bbPlayMusic( const char *src,int mode=1 );
BBSDK_API BBChannel bbPlayCDTrack( int track,int mode=1 );
#else
BBSDK_API BBChannel bbPlayMusic( const char *src,int mode );
BBSDK_API BBChannel bbPlayCDTrack( int track,int mode );
#endif
BBSDK_API void bbStopChannel( BBChannel channel );
BBSDK_API void bbPauseChannel( BBChannel channel );
BBSDK_API void bbResumeChannel( BBChannel channel );
BBSDK_API void bbChannelPitch( BBChannel channel,int pitch );
BBSDK_API void bbChannelVolume( BBChannel channel,float volume );
BBSDK_API void bbChannelPan( BBChannel channel,float pan );
BBSDK_API int bbChannelPlaying( BBChannel channel );

// bbgraphics

#ifdef __cplusplus
BBSDK_API void bbGraphics3D( int w,int h,int d=0,int mode=0 );
#else
BBSDK_API void bbGraphics3D( int w,int h,int d,int mode );
#endif
BBSDK_API int bbCountGfxDrivers();
BBSDK_API const char *bbGfxDriverName( int n );
BBSDK_API int bbGfxDriver3D( int n );

BBSDK_API int bbGfxDriverCaps3D();

BBSDK_API int bbCountGfxModes3D();
BBSDK_API int bbGfxMode3DExists( int w,int h,int d );
BBSDK_API int bbGfxMode3D( int n );
BBSDK_API int bbWindowed3D();

BBSDK_API int bbGfxDriverX( int n );
BBSDK_API int bbGfxDriverY( int n );
BBSDK_API int bbGfxDriverHz( int n );

BBSDK_API void bbSetGfxDriver( int n );
BBSDK_API int bbGfxModeExists( int w,int h,int d );
BBSDK_API int bbCountGfxModes();

BBSDK_API int bbGfxModeWidth( int n );
BBSDK_API int bbGfxModeHeight( int n );
BBSDK_API int bbGfxModeDepth( int n );

BBSDK_API int bbGraphicsWidth();
BBSDK_API int bbGraphicsHeight();
BBSDK_API int bbGraphicsDepth();

BBSDK_API int bbAvailVidMem();
BBSDK_API int bbTotalVidMem();

//mode functions

BBSDK_API void bbGraphics( int w,int h,int d,int mode );
BBSDK_API BBCanvas bbFrontBuffer();
BBSDK_API BBCanvas bbBackBuffer();
BBSDK_API void bbEndGraphics();
BBSDK_API int bbScanLine();
BBSDK_API void bbVWait( int n );
#ifdef __cplusplus
BBSDK_API void bbFlip( int vwait=1 );
#else
BBSDK_API void bbFlip( int vwait );
#endif
BBSDK_API void bbPaint( int hwnd );

//graphics buffer functions

BBSDK_API void bbSetBuffer( BBCanvas buff );
BBSDK_API BBCanvas bbGraphicsBuffer();
BBSDK_API int bbLoadBuffer( BBCanvas surf,const char *str );
BBSDK_API int bbSaveBuffer( BBCanvas surf,const char *str );

//fast read/write operations...

BBSDK_API void bbLockBuffer( BBCanvas buff );
BBSDK_API void bbUnlockBuffer( BBCanvas buff );
BBSDK_API int bbReadPixel( int x,int y,BBCanvas buff );
BBSDK_API void bbWritePixel( int x,int y,int argb,BBCanvas buff );
BBSDK_API int bbReadPixelFast( int x,int y,BBCanvas buff );
BBSDK_API void bbWritePixelFast( int x,int y,int argb,BBCanvas buff );
BBSDK_API void bbCopyPixel( int src_x,int src_y,BBCanvas src,int dest_x,int dest_y,BBCanvas buff );
BBSDK_API void bbCopyPixelFast( int src_x,int src_y,BBCanvas src,int dest_x,int dest_y,BBCanvas buff );

//2d rendering functions

BBSDK_API void bbOrigin( int x,int y );
BBSDK_API void bbViewport( int x,int y,int w,int h );
BBSDK_API void bbColor( int r,int g,int b );
BBSDK_API void bbClsColor( int r,int g,int b );
BBSDK_API void bbCls();
BBSDK_API void bbPlot( int x,int y );
BBSDK_API void bbLine( int x1,int y1,int x2,int y2 );
#ifdef __cplusplus
BBSDK_API void bbRect( int x,int y,int w,int h,int solid=1 );
BBSDK_API void bbOval( int x,int y,int w,int h,int solid=1 );
BBSDK_API void bbText( int x,int y,const char *t,int centre_x=0,int centre_y=0 );
#else
BBSDK_API void bbRect( int x,int y,int w,int h,int solid );
BBSDK_API void bbOval( int x,int y,int w,int h,int solid );
BBSDK_API void bbText( int x,int y,const char *t,int centre_x,int centre_y );
#endif
BBSDK_API void bbCopyRect( int sx,int sy,int w,int h,int dx,int dy,BBCanvas src,BBCanvas dest );
BBSDK_API void bbGetColor( int x,int y );
BBSDK_API int bbColorRed();
BBSDK_API int bbColorGreen();
BBSDK_API int bbColorBlue();

//font functions

BBSDK_API BBFont bbLoadFont( const char *name,int height,int bold,int italic,int underline );
BBSDK_API void bbFreeFont( BBFont f );
BBSDK_API void bbSetFont( BBFont f );
BBSDK_API int bbFontWidth();
BBSDK_API int bbFontHeight();
BBSDK_API int bbStringWidth( const char *str );
BBSDK_API int bbStringHeight( const char *str );

//image functions

BBSDK_API BBImage bbLoadImage( const char *s );
BBSDK_API BBImage bbCopyImage( BBImage sourceimage );
BBSDK_API BBImage bbCreateImage( int w,int h,int n );
BBSDK_API BBImage bbLoadAnimImage( const char *s,int w,int h,int first,int cnt );
BBSDK_API void bbFreeImage( BBImage i );
BBSDK_API int bbSaveImage( BBImage i,const char *filename,int frame );
BBSDK_API void bbGrabImage( BBImage i,int x,int y,int n );
BBSDK_API BBCanvas bbImageBuffer( BBImage i,int n );
BBSDK_API void bbDrawImage( BBImage i,int x,int y,int frame );
BBSDK_API void bbDrawBlock( BBImage i,int x,int y,int frame );
BBSDK_API void bbTileImage( BBImage i,int x,int y,int frame );
BBSDK_API void bbTileBlock( BBImage i,int x,int y,int frame );
BBSDK_API void bbDrawImageRect( BBImage i,int x,int y,int r_x,int r_y,int r_w,int r_h,int frame );
BBSDK_API void bbDrawBlockRect( BBImage i,int x,int y,int r_x,int r_y,int r_w,int r_h,int frame );
BBSDK_API void bbMaskImage( BBImage i,int r,int g,int b );
BBSDK_API void bbHandleImage( BBImage i,int x,int y );
BBSDK_API void bbScaleImage( BBImage i,float w,float h );
BBSDK_API void bbResizeImage( BBImage i,float w,float h );
BBSDK_API void bbRotateImage( BBImage i,float angle );
BBSDK_API void bbTFormImage( BBImage i,float a,float b,float c,float d );
BBSDK_API void bbTFormFilter( int enable );
BBSDK_API void bbAutoMidHandle( int enable );
BBSDK_API void bbMidHandle( BBImage i );
BBSDK_API int bbImageWidth( BBImage i );
BBSDK_API int bbImageHeight( BBImage i );
BBSDK_API int bbImageXHandle( BBImage i );
BBSDK_API int bbImageYHandle( BBImage i );
BBSDK_API int bbImagesOverlap( BBImage i1,int x1,int y1,BBImage i2,int x2,int y2 );
BBSDK_API int bbImagesCollide( BBImage i1,int x1,int y1,int f1,BBImage i2,int x2,int y2,int f2 );
BBSDK_API int bbRectsOverlap( int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 );
BBSDK_API int bbImageRectOverlap( BBImage i,int x,int y,int r_x,int r_y,int r_w,int r_h );
BBSDK_API int bbImageRectCollide( BBImage i,int x,int y,int f,int r_x,int r_y,int r_w,int r_h );

BBSDK_API void bbWrite( const char *str );
BBSDK_API void bbPrint( const char *str );
BBSDK_API const char *bbInput( const char *prompt );
BBSDK_API void bbLocate( int x,int y );

// movie commands

BBSDK_API BBMovie bbOpenMovie( const char *s );
BBSDK_API int bbDrawMovie( BBMovie movie,int x,int y,int w,int h );
BBSDK_API int bbMovieWidth( BBMovie movie );
BBSDK_API int bbMovieHeight( BBMovie movie );
BBSDK_API int bbMoviePlaying( BBMovie movie );
BBSDK_API void bbCloseMovie( BBMovie movie );

// gamma commands

BBSDK_API void bbSetGamma( int r,int g,int b,float dr,float dg,float db );
BBSDK_API void bbUpdateGamma( int calibrate );
BBSDK_API float bbGammaRed( int n );
BBSDK_API float bbGammaGreen( int n );
BBSDK_API float bbGammaBlue( int n );

// bbgraphics3d

// global world commands 

BBSDK_API void bbLoaderMatrix( const char *ext,float xx,float xy,float xz,float yx,float yy,float yz,float zx,float zy,float zz );
BBSDK_API int bbHWTexUnits();

BBSDK_API void bbHWMultiTex( int enable );
BBSDK_API void bbWBuffer( int enable );
BBSDK_API void bbDither( int enable );
BBSDK_API void bbAntiAlias( int enable );
BBSDK_API void bbWireFrame( int enable );
BBSDK_API void bbAmbientLight( float r,float g,float b );
BBSDK_API void bbClearCollisions();

BBSDK_API void bbCollisions( int src_type,int dest_type,int method,int response );

#ifdef __cplusplus
BBSDK_API void bbUpdateWorld( float elapsed=1.0 );
BBSDK_API void bbRenderWorld( float tween=1.0 );
#else
BBSDK_API void bbUpdateWorld( float elapsed );
BBSDK_API void bbRenderWorld( float tween );
#endif
BBSDK_API void bbCaptureWorld();
BBSDK_API int bbTrisRendered();
BBSDK_API float bbStats3D( int n );

// texture commands
#ifdef __cplusplus
BBSDK_API BBTexture bbLoadTexture( const char *file,int flags=1 );
BBSDK_API BBTexture bbCreateTexture( int w,int h,int flags=3,int frames=1 );
#else
BBSDK_API BBTexture bbLoadTexture( const char *file,int flags );
BBSDK_API BBTexture bbCreateTexture( int w,int h,int flags,int frames );
#endif
BBSDK_API BBTexture bbLoadAnimTexture( const char *file,int flags,int w,int h,int first,int cnt );
BBSDK_API void bbFreeTexture( BBTexture t );
BBSDK_API void bbTextureBlend( BBTexture t,int blend );
BBSDK_API void bbTextureCoords( BBTexture t,int flags );
BBSDK_API void bbScaleTexture( BBTexture t,float u_scale,float v_scale );
BBSDK_API void bbRotateTexture( BBTexture t,float angle );
BBSDK_API void bbPositionTexture( BBTexture t,float u_pos,float v_pos );
BBSDK_API int bbTextureWidth( BBTexture t );
BBSDK_API int bbTextureHeight( BBTexture t );


BBSDK_API const char *bbTextureName( BBTexture t );
BBSDK_API void bbSetCubeFace( BBTexture t,int face );
BBSDK_API void bbSetCubeMode( BBTexture t,int mode );
#ifdef __cplusplus
BBSDK_API BBCanvas bbTextureBuffer( BBTexture t,int frame=0 );
#else
BBSDK_API BBCanvas bbTextureBuffer( BBTexture t,int frame );
#endif
BBSDK_API void bbClearTextureFilters();
BBSDK_API void bbTextureFilter( const char *t,int flags );

// brush commands

#ifdef __cplusplus
BBSDK_API BBBrush bbCreateBrush( float r=255.0f,float g=255.0f,float b=255.0f );
BBSDK_API BBBrush bbLoadBrush( const char *file,int flags=1,float u_scale=1.0,float v_scale=1.0 );
#else
BBSDK_API BBBrush bbCreateBrush( float r,float g,float b );
BBSDK_API BBBrush bbLoadBrush( const char *file,int flags,float u_scale,float v_scale );
#endif

BBSDK_API void bbFreeBrush( BBBrush b );
BBSDK_API void bbBrushColor( BBBrush br,float r,float g,float b );
BBSDK_API void bbBrushAlpha( BBBrush b,float alpha );
BBSDK_API void bbBrushShininess( BBBrush b,float n );
BBSDK_API void bbBrushTexture( BBBrush b,BBTexture t,int frame,int index );
BBSDK_API BBTexture bbGetBrushTexture( BBBrush b,int index );
BBSDK_API void bbBrushBlend( BBBrush b,int blend );
BBSDK_API void bbBrushFX( BBBrush b,int fx );

// mesh commands
#ifdef __cplusplus
BBSDK_API BBModel bbCreateMesh( BBEntity p=0 );
BBSDK_API BBModel bbLoadMesh( const char *f,BBEntity p=0 );
BBSDK_API BBModel bbLoadAnimMesh( const char *f,BBEntity p=0 );
BBSDK_API BBModel bbCreateCube( BBEntity p=0 );
BBSDK_API BBModel bbCreateSphere( int segs=8,BBEntity p=0 );
BBSDK_API BBModel bbCreateCylinder( int segs=8,int solid=1,BBEntity p=0 );
BBSDK_API BBModel bbCreateCone( int segs=8,int solid=1,BBEntity p=0 );
BBSDK_API BBModel bbCopyMesh( BBModel m,BBEntity p=0 );
#else
BBSDK_API BBModel bbCreateMesh( BBEntity p );
BBSDK_API BBModel bbLoadMesh( const char *f,BBEntity p );
BBSDK_API BBModel bbLoadAnimMesh( const char *f,BBEntity p );
BBSDK_API BBModel bbCreateCube( BBEntity p );
BBSDK_API BBModel bbCreateSphere( int segs,BBEntity p );
BBSDK_API BBModel bbCreateCylinder( int segs,int solid,BBEntity p );
BBSDK_API BBModel bbCreateCone( int segs,int solid,BBEntity p );
BBSDK_API BBModel bbCopyMesh( BBModel m,BBEntity p );
#endif
BBSDK_API void bbScaleMesh( BBModel m,float x,float y,float z );
BBSDK_API void bbRotateMesh( BBModel m,float x,float y,float z );
BBSDK_API void bbPositionMesh( BBModel m,float x,float y,float z );
#ifdef __cplusplus
BBSDK_API void bbFitMesh( BBModel m,float x,float y,float z,float w,float h,float d,int uniform=0 );
#else
BBSDK_API void bbFitMesh( BBModel m,float x,float y,float z,float w,float h,float d,int uniform );
#endif
BBSDK_API void bbFlipMesh( BBModel m );
BBSDK_API void bbPaintMesh( BBModel m,BBBrush b );
BBSDK_API void bbAddMesh( BBModel src,BBModel dest );
BBSDK_API void bbUpdateNormals( BBModel m );
BBSDK_API void bbLightMesh( BBModel m,float r,float g,float b,float range,float x,float y,float z );
BBSDK_API float bbMeshWidth( BBModel m );
BBSDK_API float bbMeshHeight( BBModel m );
BBSDK_API float bbMeshDepth( BBModel m );
BBSDK_API int bbMeshesIntersect( BBModel a,BBModel b );
BBSDK_API int bbCountSurfaces( BBModel m );
BBSDK_API BBSurface bbGetSurface( BBModel m,int index );
BBSDK_API void bbMeshCullBox( BBModel m,float x,float y,float z,float w,float h,float d );

// surface commands

#ifdef __cplusplus
BBSDK_API BBSurface bbCreateSurface( BBModel m,BBBrush b=0 );
#else
BBSDK_API BBSurface bbCreateSurface( BBModel m,BBBrush b );
#endif
BBSDK_API BBSurface bbFindSurface( BBModel m,BBBrush b );
BBSDK_API BBBrush bbGetSurfaceBrush( BBSurface s );
BBSDK_API BBBrush bbGetEntityBrush( BBModel m );

BBSDK_API void bbClearSurface( BBSurface s,int verts,int tris );
BBSDK_API void bbPaintSurface( BBSurface s,BBBrush b );
#ifdef __cplusplus
BBSDK_API int bbAddVertex( BBSurface s,float x,float y,float z,float tu=0.0f,float tv=0.0f,float tw=0.0f );
#else
BBSDK_API int bbAddVertex( BBSurface s,float x,float y,float z,float tu,float tv,float tw );
#endif
BBSDK_API int bbAddTriangle( BBSurface s,int v0,int v1,int v2 );
BBSDK_API void bbVertexCoords( BBSurface s,int n,float x,float y,float z );
BBSDK_API void bbVertexNormal( BBSurface s,int n,float x,float y,float z );

BBSDK_API void bbVertexColor( BBSurface s,int n,float r,float g,float b,float a );
BBSDK_API void bbVertexTexCoords( BBSurface s,int n,float u,float v,float w,int set );
BBSDK_API int bbCountVertices( BBSurface s );
BBSDK_API int bbCountTriangles( BBSurface s );
BBSDK_API float bbVertexX( BBSurface s,int n );
BBSDK_API float bbVertexY( BBSurface s,int n );
BBSDK_API float bbVertexZ( BBSurface s,int n );
BBSDK_API float bbVertexNX( BBSurface s,int n );
BBSDK_API float bbVertexNY( BBSurface s,int n );
BBSDK_API float bbVertexNZ( BBSurface s,int n );
BBSDK_API float bbVertexRed( BBSurface s,int n );
BBSDK_API float bbVertexGreen( BBSurface s,int n );
BBSDK_API float bbVertexBlue( BBSurface s,int n );
BBSDK_API float bbVertexAlpha( BBSurface s,int n );
BBSDK_API float bbVertexU( BBSurface s,int n,int t );
BBSDK_API float bbVertexV( BBSurface s,int n,int t );
BBSDK_API float bbVertexW( BBSurface s,int n,int t );
BBSDK_API int bbTriangleVertex( BBSurface s,int n,int v );

// camera commands

#ifdef __cplusplus
BBSDK_API BBCamera bbCreateCamera( BBEntity p=0 );
#else
BBSDK_API BBCamera bbCreateCamera( BBEntity p );
#endif
BBSDK_API void bbCameraZoom( BBCamera c,float zoom );
BBSDK_API void bbCameraRange( BBCamera c,float nr,float fr );
BBSDK_API void bbCameraClsColor( BBCamera c,float r,float g,float b );
BBSDK_API void bbCameraClsMode( BBCamera c,int cls_color,int cls_zbuffer );
BBSDK_API void bbCameraProjMode( BBCamera c,int mode );
BBSDK_API void bbCameraViewport( BBCamera c,int x,int y,int w,int h );
BBSDK_API void bbCameraFogRange( BBCamera c,float nr,float fr );
BBSDK_API void bbCameraFogColor( BBCamera c,float r,float g,float b );
BBSDK_API void bbCameraFogMode( BBCamera c,int mode );
BBSDK_API int bbCameraProject( BBCamera c,float x,float y,float z );
BBSDK_API float bbProjectedX();
BBSDK_API float bbProjectedY();
BBSDK_API float bbProjectedZ();
BBSDK_API BBEntity bbCameraPick( BBCamera c,float x,float y );
BBSDK_API BBEntity bbLinePick( float x,float y,float z,float dx,float dy,float dz,float radius );
BBSDK_API BBEntity bbEntityPick( BBObject src,float range );
BBSDK_API int bbEntityVisible( BBObject src,BBObject dest );
BBSDK_API int bbEntityInView( BBEntity e,BBCamera c );
BBSDK_API float bbPickedX();
BBSDK_API float bbPickedY();
BBSDK_API float bbPickedZ();
BBSDK_API float bbPickedNX();
BBSDK_API float bbPickedNY();
BBSDK_API float bbPickedNZ();
BBSDK_API float bbPickedTime();
BBSDK_API BBObject bbPickedEntity();
BBSDK_API BBSurface bbPickedSurface();
BBSDK_API int bbPickedTriangle();

// light commands

#ifdef __cplusplus
BBSDK_API BBLight bbCreateLight( int type=0,BBEntity p=0 );
#else
BBSDK_API BBLight bbCreateLight( int type,BBEntity p );
#endif
BBSDK_API void bbLightColor( BBLight light,float r,float g,float b );
BBSDK_API void bbLightRange( BBLight light,float range );
BBSDK_API void bbLightConeAngles( BBLight light,float inner,float outer );

// pivot commands

#ifdef __cplusplus
BBSDK_API BBPivot bbCreatePivot( BBEntity p=0 );
#else
BBSDK_API BBPivot bbCreatePivot( BBEntity p );
#endif

// sprite commands
#ifdef __cplusplus
BBSDK_API BBSprite bbCreateSprite( BBEntity p=0 );
BBSDK_API BBSprite bbLoadSprite( const char *file,int flags=1,BBEntity p=0 );
#else
BBSDK_API BBSprite bbCreateSprite( BBEntity p );
BBSDK_API BBSprite bbLoadSprite( const char *file,int flags,BBEntity p );
#endif
BBSDK_API void bbRotateSprite( BBSprite s,float angle );
BBSDK_API void bbScaleSprite( BBSprite s,float x,float y );
BBSDK_API void bbHandleSprite( BBSprite s,float x,float y );
BBSDK_API void bbSpriteViewMode( BBSprite s,int mode );

// mirror commands
#ifdef __cplusplus
BBSDK_API BBMirror bbCreateMirror( BBEntity p=0 );
#else
BBSDK_API BBMirror bbCreateMirror( BBEntity p );
#endif

// plane commands
#ifdef __cplusplus
BBSDK_API BBPlaneModel bbCreatePlane( int segs=1,BBEntity p=0 );
#else
BBSDK_API BBPlaneModel bbCreatePlane( int segs,BBEntity p );
#endif

// md2 commands
#ifdef __cplusplus
BBSDK_API BBMD2Model bbLoadMD2( const char *file,BBEntity p=0 );
BBSDK_API void bbAnimateMD2( BBMD2Model m,int mode=1,float speed=1.0,int first=0,int last=9999,float trans=0.0 );
#else
BBSDK_API BBMD2Model bbLoadMD2( const char *file,BBEntity p );
BBSDK_API void bbAnimateMD2( BBMD2Model m,int mode,float speed,int first,int last,float trans );
#endif
BBSDK_API float bbMD2AnimTime( BBMD2Model m );
BBSDK_API int bbMD2AnimLength( BBMD2Model m );
BBSDK_API int bbMD2Animating( BBMD2Model m );

// bsp commands
#ifdef __cplusplus
BBSDK_API BBQ3BSPModel bbLoadBSP( const char *file,float gam,BBEntity p=0 );
#else
BBSDK_API BBQ3BSPModel bbLoadBSP( const char *file,float gam,BBEntity p );
#endif
BBSDK_API void bbBSPAmbientLight( BBQ3BSPModel t,float r,float g,float b );
BBSDK_API void bbBSPLighting( BBQ3BSPModel t,int lmap );

// terrain commands
#ifdef __cplusplus
BBSDK_API BBTerrain bbCreateTerrain( int n,BBEntity p=0 );
BBSDK_API BBTerrain bbLoadTerrain( const char *file,BBEntity p=0 );
#else
BBSDK_API BBTerrain bbCreateTerrain( int n,BBEntity p );
BBSDK_API BBTerrain bbLoadTerrain( const char *file,BBEntity p );
#endif
BBSDK_API void bbTerrainDetail( BBTerrain t,int n,int m );
BBSDK_API void bbTerrainShading( BBTerrain t,int enable );
BBSDK_API float bbTerrainX( BBTerrain t,float x,float y,float z );
BBSDK_API float bbTerrainY( BBTerrain t,float x,float y,float z );
BBSDK_API float bbTerrainZ( BBTerrain t,float x,float y,float z );
BBSDK_API int bbTerrainSize( BBTerrain t );
BBSDK_API float bbTerrainHeight( BBTerrain t,int x,int z );
BBSDK_API void bbModifyTerrain( BBTerrain t,int x,int z,float h,int realtime );

// audio commands
#ifdef __cplusplus
BBSDK_API BBEntity bbCreateListener( BBEntity p=0,float roll=1.0,float dopp=1.0,float dist=1.0 );
#else
BBSDK_API BBEntity bbCreateListener( BBEntity p,float roll,float dopp,float dist );
#endif
BBSDK_API BBChannel bbEmitSound( BBSound sound,BBObject o );

// entity commands
#ifdef __cplusplus
BBSDK_API BBEntity bbCopyEntity( BBEntity e,BBEntity p=0 );
#else
BBSDK_API BBEntity bbCopyEntity( BBEntity e,BBEntity p );
#endif
BBSDK_API void bbFreeEntity( BBEntity e );
BBSDK_API void bbHideEntity( BBEntity e );
BBSDK_API void bbShowEntity( BBEntity e );
#ifdef __cplusplus
BBSDK_API void bbEntityParent( BBEntity e,BBEntity p=0,int global=1 );
#else
BBSDK_API void bbEntityParent( BBEntity e,BBEntity p,int global );
#endif
BBSDK_API int bbCountChildren( BBEntity e );
BBSDK_API BBEntity bbGetChild( BBEntity e,int index );
BBSDK_API BBEntity bbFindChild( BBEntity e,const char *t );

// animation commands

BBSDK_API int bbLoadAnimSeq( BBObject o,const char *f );
BBSDK_API void bbSetAnimTime( BBObject o,float time,int seq );
#ifdef __cplusplus
BBSDK_API void bbAnimate( BBObject o,int mode=1,float speed=1.0f,int seq=0,float trans=0.0f );
BBSDK_API void bbSetAnimKey( BBObject o,int frame,int pos_key=1,int rot_key=1,int scl_key=1 );
#else
BBSDK_API void bbAnimate( BBObject o,int mode,float speed,int seq,float trans );
BBSDK_API void bbSetAnimKey( BBObject o,int frame,int pos_key,int rot_key,int scl_key );
#endif
BBSDK_API int bbExtractAnimSeq( BBObject o,int first,int last,int seq );
BBSDK_API int bbAddAnimSeq( BBObject o,int length );
BBSDK_API int bbAnimSeq( BBObject o );
BBSDK_API float bbAnimTime( BBObject o );
BBSDK_API int bbAnimLength( BBObject o );
BBSDK_API int bbAnimating( BBObject o );

// entity special fx commands

BBSDK_API void bbPaintEntity( BBEntity e,BBBrush b );
BBSDK_API void bbEntityColor( BBModel m,float r,float g,float b );
BBSDK_API void bbEntityAlpha( BBModel m,float alpha );
BBSDK_API void bbEntityShininess( BBModel m,float shininess );
#ifdef __cplusplus
BBSDK_API void bbEntityTexture( BBModel m,BBTexture t,int frame=0,int index=0 );
#else
BBSDK_API void bbEntityTexture( BBModel m,BBTexture t,int frame,int index );
#endif
BBSDK_API void bbEntityBlend( BBModel m,int blend );
BBSDK_API void bbEntityFX( BBModel m,int fx );
BBSDK_API void bbEntityAutoFade( BBModel m,float nr,float fr );
BBSDK_API void bbEntityOrder( BBObject o,int n );

// entity property commands

#ifdef __cplusplus
BBSDK_API float bbEntityX( BBEntity e,int global=1 );
BBSDK_API float bbEntityY( BBEntity e,int global=1 );
BBSDK_API float bbEntityZ( BBEntity e,int global=1 );
BBSDK_API float bbEntityPitch( BBEntity e,int global=1 );
BBSDK_API float bbEntityYaw( BBEntity e,int global=1 );
BBSDK_API float bbEntityRoll( BBEntity e,int global=1 );
#else
BBSDK_API float bbEntityX( BBEntity e,int global );
BBSDK_API float bbEntityY( BBEntity e,int global );
BBSDK_API float bbEntityZ( BBEntity e,int global );
BBSDK_API float bbEntityPitch( BBEntity e,int global );
BBSDK_API float bbEntityYaw( BBEntity e,int global );
BBSDK_API float bbEntityRoll( BBEntity e,int global );
#endif
BBSDK_API float bbGetMatElement( BBEntity e,int row,int col );
BBSDK_API void bbTFormPoint( float x,float y,float z,BBEntity src,BBEntity dest );
BBSDK_API void bbTFormVector( float x,float y,float z,BBEntity src,BBEntity dest );
BBSDK_API void bbTFormNormal( float x,float y,float z,BBEntity src,BBEntity dest );
BBSDK_API float bbTFormedX();
BBSDK_API float bbTFormedY();
BBSDK_API float bbTFormedZ();
BBSDK_API float bbVectorYaw( float x,float y,float z );
BBSDK_API float bbVectorPitch( float x,float y,float z );
BBSDK_API float bbDeltaYaw( BBEntity src,BBEntity dest );
BBSDK_API float bbDeltaPitch( BBEntity src,BBEntity dest );

// entity collision commands

BBSDK_API void bbResetEntity( BBObject o );
BBSDK_API void bbCaptureEntity( BBObject o );
#ifdef __cplusplus
BBSDK_API void bbEntityType( BBObject o,int type,int recurs=0 );
#else
BBSDK_API void bbEntityType( BBObject o,int type,int recurs );
#endif
BBSDK_API void bbEntityPickMode( BBObject o,int mode,int obs );
BBSDK_API BBEntity bbGetParent( BBEntity e );
BBSDK_API int bbGetEntityType( BBObject o );
#ifdef __cplusplus
BBSDK_API void bbEntityRadius( BBObject o,float x_radius,float y_radius=0.0 );
#else
BBSDK_API void bbEntityRadius( BBObject o,float x_radius,float y_radius );
#endif
BBSDK_API void bbEntityBox( BBObject o,float x,float y,float z,float w,float h,float d );
BBSDK_API BBObject bbEntityCollided( BBObject o,int type );
BBSDK_API int bbCountCollisions( BBObject o );
BBSDK_API float bbCollisionX( BBObject o,int index );
BBSDK_API float bbCollisionY( BBObject o,int index );
BBSDK_API float bbCollisionZ( BBObject o,int index );
BBSDK_API float bbCollisionNX( BBObject o,int index );
BBSDK_API float bbCollisionNY( BBObject o,int index );
BBSDK_API float bbCollisionNZ( BBObject o,int index );
BBSDK_API float bbCollisionTime( BBObject o,int index );
BBSDK_API BBObject bbCollisionEntity( BBObject o,int index );
BBSDK_API BBSurface bbCollisionSurface( BBObject o,int index );
BBSDK_API int bbCollisionTriangle( BBObject o,int index );
BBSDK_API float bbEntityDistance( BBEntity src,BBEntity dest );

// entity transformation commands

BBSDK_API void bbMoveEntity( BBEntity e,float x,float y,float z );
#ifdef __cplusplus
BBSDK_API void bbTurnEntity( BBEntity e,float p,float y,float r,int global=1 );
BBSDK_API void bbTranslateEntity( BBEntity e,float x,float y,float z,int global=1 );
BBSDK_API void bbPositionEntity( BBEntity e,float x,float y,float z,int global=1 );
BBSDK_API void bbScaleEntity( BBEntity e,float x,float y,float z,int global=1 );
BBSDK_API void bbRotateEntity( BBEntity e,float p,float y,float r,int global=1 );
BBSDK_API void bbPointEntity( BBEntity e,BBEntity t,float roll=0 );
#else
BBSDK_API void bbTurnEntity( BBEntity e,float p,float y,float r,int global );
BBSDK_API void bbTranslateEntity( BBEntity e,float x,float y,float z,int global );
BBSDK_API void bbPositionEntity( BBEntity e,float x,float y,float z,int global );
BBSDK_API void bbScaleEntity( BBEntity e,float x,float y,float z,int global );
BBSDK_API void bbRotateEntity( BBEntity e,float p,float y,float r,int global );
BBSDK_API void bbPointEntity( BBEntity e,BBEntity t,float roll );
#endif
BBSDK_API void bbAlignToVector( BBEntity e,float nx,float ny,float nz,int axis,float rate );

// entity misc commands

BBSDK_API void bbNameEntity( BBEntity e,const char *t );
BBSDK_API const char *bbEntityName( BBEntity e );
BBSDK_API const char *bbEntityClass( BBEntity e );
BBSDK_API void bbClearWorld( int e,int b,int t );
BBSDK_API void bbSetEntityID( BBEntity *e,int id );
BBSDK_API int bbEntityID( BBEntity *e );

BBSDK_API int bbActiveTextures();

#ifdef __cplusplus
}
#endif

#endif
