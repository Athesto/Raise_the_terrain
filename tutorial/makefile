flags1=-g -Wall -Wextra -Werror -pedantic `sdl2-config --libs` `sdl2-config --cflags`

1:
	gcc test/1-demo.c $(flags1)

2:
	gcc test/2-demo-Instance.c init_instance.c $(flags1)

3:
	gcc test/3-demo-inf.c init_instance.c $(flags1)

4:
	gcc test/4-demo-line.c init_instance.c void_draw_stuff.c $(flags1)

5:
	gcc test/5-demo-poll.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)

6:
	gcc test/6-*.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)

7:
	gcc test/7-*.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)

8:
	gcc test/8-*.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)

9:
	gcc test/9-*.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)
