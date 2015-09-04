#include "Tunnel.h"
// SDL ��ر�������
SDL_Surface *screen,*bBuffer,*Image;
SDL_Rect rScreen,rBuffer;
int main (int argc, char **argv)
{
��int flag = SDL_SWSURFACE;// ����һ���������.
��//������洦��ϵͳ�ڴ��У�
��// һ�㲻��Ӳ�������ٶȿ�
��#ifdef WIN32
��int fullscreen = MessageBox(NULL, "Show Full Screen (y/n):","Screen Setting", MB_YESNO);
��if (fullscreen==IDYES) {
����flag |= SDL_FULLSCREEN; // ����û���Ҫ���ӹ�������Ļ
��}
��#endif
��Tunnel_Timer(); // ��ȡ��ʼ��ϵͳʱ��ֵ
��SDL_Init( SDL_INIT_VIDEO ); // ��ʼ����Ƶ��ϵͳ
��//����Ļ���õ� 320x240��32λ��ɫ
��screen = SDL_SetVideoMode( 320, 240, 32, flag);
��// ������õĻ���Ϊ��Ļ��������Ӳ������
��bBuffer = SDL_CreateRGBSurface( SDL_HWSURFACE, screen->w,screen->h,screen->format->BitsPerPixel,
��������screen->format->Rmask,
��������screen->format->Gmask,
��������screen->format->Bmask,
��������screen->format->Amask);
��// ��������ͼ��һ����ʼ���ͻ���������
��Image = SDL_LoadBMP( "tunnel_map.bmp" );
��Image = SDL_ConvertSurface(Image, screen->format, SDL_HWSURFACE);
��rBuffer.x = 0;
��rBuffer.y = 0;
��rBuffer.w = bBuffer->w;
��rBuffer.h = bBuffer->h;
��// ���Ӵ�����¼�, ���� ��궯���� ��ȡ�����
��SDL_EventState(SDL_ACTIVEEVENT, SDL_IGNORE);
��SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
��SDL_ShowCursor( SDL_DISABLE );
��Tunnel.Set( 320, 240 ); // ͨ������������Ļ�����
��Tunnel.Precalc( 16 ); //�ڲ���ԲȦֱ��
��while (SDL_PollEvent(NULL)==0) {
����float fTime = Tunnel_GetTime();
����//���޸�ǰ�������������棬�ر𵱻���������ͼ��Ӳ���ڴ���ʱ
����SDL_LockSurface(bBuffer);
����SDL_LockSurface(Image);
����Tunnel.Draw(bBuffer, Image, 180*sin(fTime), fTime*100);
����SDL_UnlockSurface(bBuffer); // �ڸ����Ժ�����Կ���
����SDL_UnlockSurface(Image);
����// �ѻ������е������������Ļ��ͼ����ǿ�Ƚ����ػ�
����SDL_BlitSurface( bBuffer, NULL, screen, &rBuffer );
����SDL_UpdateRect( screen, 0, 0, 0, 0 );
��}
��Tunnel.Free();
}
