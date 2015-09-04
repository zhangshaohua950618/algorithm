#include "Tunnel.h"
// SDL 相关变量定义
SDL_Surface *screen,*bBuffer,*Image;
SDL_Rect rScreen,rBuffer;
int main (int argc, char **argv)
{
　int flag = SDL_SWSURFACE;// 请求一个软件表面.
　//软件表面处于系统内存中，
　// 一般不如硬件表面速度快
　#ifdef WIN32
　int fullscreen = MessageBox(NULL, "Show Full Screen (y/n):","Screen Setting", MB_YESNO);
　if (fullscreen==IDYES) {
　　flag |= SDL_FULLSCREEN; // 如果用户需要，接管整个屏幕
　}
　#endif
　Tunnel_Timer(); // 读取起始的系统时钟值
　SDL_Init( SDL_INIT_VIDEO ); // 初始化视频子系统
　//把屏幕设置到 320x240，32位颜色
　screen = SDL_SetVideoMode( 320, 240, 32, flag);
　// 如果可用的话，为屏幕表面请求硬件缓冲
　bBuffer = SDL_CreateRGBSurface( SDL_HWSURFACE, screen->w,screen->h,screen->format->BitsPerPixel,
　　　　screen->format->Rmask,
　　　　screen->format->Gmask,
　　　　screen->format->Bmask,
　　　　screen->format->Amask);
　// 这是种子图像，一旦开始它就会盘旋起来
　Image = SDL_LoadBMP( "tunnel_map.bmp" );
　Image = SDL_ConvertSurface(Image, screen->format, SDL_HWSURFACE);
　rBuffer.x = 0;
　rBuffer.y = 0;
　rBuffer.w = bBuffer->w;
　rBuffer.h = bBuffer->h;
　// 忽视大多数事件, 包括 鼠标动作， 并取消光标
　SDL_EventState(SDL_ACTIVEEVENT, SDL_IGNORE);
　SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
　SDL_ShowCursor( SDL_DISABLE );
　Tunnel.Set( 320, 240 ); // 通道将填充整个的缓冲区
　Tunnel.Precalc( 16 ); //内部的圆圈直径
　while (SDL_PollEvent(NULL)==0) {
　　float fTime = Tunnel_GetTime();
　　//在修改前，必须锁定表面，特别当缓冲区处于图形硬件内存中时
　　SDL_LockSurface(bBuffer);
　　SDL_LockSurface(Image);
　　Tunnel.Draw(bBuffer, Image, 180*sin(fTime), fTime*100);
　　SDL_UnlockSurface(bBuffer); // 在更新以后你可以开锁
　　SDL_UnlockSurface(Image);
　　// 把缓冲区中的数据输出到屏幕绘图区域并强迫进行重画
　　SDL_BlitSurface( bBuffer, NULL, screen, &rBuffer );
　　SDL_UpdateRect( screen, 0, 0, 0, 0 );
　}
　Tunnel.Free();
}
