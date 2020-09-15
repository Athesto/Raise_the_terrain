flags1=-g -Wall -Wextra -Werror -pedantic `sdl2-config --libs` `sdl2-config --cflags`

demo1:
	gcc test/1-demo.c $(flags1)

demo2:
	gcc test/2-demo-Instance.c init_instance.c $(flags1)

demo3:
	gcc test/3-demo-inf.c init_instance.c $(flags1)

demo4:
	gcc test/4-demo-line.c init_instance.c void_draw_stuff.c $(flags1)

demo5:
	gcc test/5-demo-poll.c init_instance.c void_draw_stuff.c poll_events.c $(flags1)
