#include "fdf.h"

t_env env; 

t_point3d rotate_x(t_point3d p, float angle) {
    t_point3d rotated_p;
    rotated_p.x = p.x;
    rotated_p.y = p.y * cos(angle) - p.z * sin(angle);
    rotated_p.z = p.y * sin(angle) + p.z * cos(angle);
    return rotated_p;
}

t_point3d rotate_y(t_point3d p, float angle) {
    t_point3d rotated_p;
    rotated_p.x = p.x * cos(angle) + p.z * sin(angle);
    rotated_p.y = p.y;
    rotated_p.z = -p.x * sin(angle) + p.z * cos(angle);
    return rotated_p;
}

t_point3d rotate_z(t_point3d p, float angle) {
    t_point3d rotated_p;
    rotated_p.x = p.x * cos(angle) - p.y * sin(angle);
    rotated_p.y = p.x * sin(angle) + p.y * cos(angle);
    rotated_p.z = p.z;
    return rotated_p;
}

t_point3d rotate_around_point(t_point3d p, t_env *env) {
    // Traslación al punto de rotación
    p.x -= env->rotation_point.x;
    p.y -= env->rotation_point.y;
    p.z -= env->rotation_point.z;

    // Aplicar rotaciones
    p = rotate_x(p, env->rotation_x);
    p = rotate_y(p, env->rotation_y);
    p = rotate_z(p, env->rotation_z);

    // Traslación inversa
    p.x += env->rotation_point.x;
    p.y += env->rotation_point.y;
    p.z += env->rotation_point.z;

    return p;
}


void draw_line_3d(t_env *env) {

    for (size_t i = 0; i < 12; i++)
    {
        t_line line = env->lines[i];
        t_point3d start_2d = { line.start.x, line.start.y, 0 }; // Proyección simplificada
        t_point3d end_2d = { line.end.x, line.end.y, 0 };

        int dx = end_2d.x - start_2d.x;
        int dy = end_2d.y - start_2d.y;
        int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

        float x_inc = dx / (float)steps;
        float y_inc = dy / (float)steps;

        float x = start_2d.x;
        float y = start_2d.y;

        for (int i = 0; i <= steps; i++) {
            mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0xFFFFFF); // Dibuja en blanco
            x += x_inc;
            y += y_inc;
        }
    }
    
}

int key_hook(int keycode, t_env *env) {
    const float rotation_speed = M_PI / 180; // Ajusta la velocidad de rotación aquí
    if (keycode == 120) {
        if (env->rotation_x < 360) // Reemplaza KEY_X, KEY_Y, KEY_Z con los códigos de tecla reales
            env->rotation_x += rotation_speed;
        else
            env->rotation_x = 0;

    } else if (keycode == 121) {
        if (env->rotation_y < 360)
            env->rotation_y += rotation_speed;
        else
            env->rotation_y = 0;

    } else if (keycode == 122) {
        if (env->rotation_z < 360)
            env->rotation_z += rotation_speed;
        else
            env->rotation_z = 0;
    }

    // Aplicar rotaciones
    for (size_t i = 0; i < 12; i++)
    {
        t_line *line = &env->lines[i];
        line->start = rotate_around_point(line->start, env);
        line->end = rotate_around_point(line->end, env);
    }

    // Redibujar la línea
    mlx_clear_window(env->mlx_ptr, env->win_ptr);
    draw_line_3d(env);

    return 0;
}


int main() {
    int fd = open("./maps/test_maps/10-2.fdf", 0);
    char *line = get_next_line(fd);
    char **str = ft_split(line, ' ');
   
    
    env.mlx_ptr = mlx_init();
    env.win_ptr = mlx_new_window(env.mlx_ptr, 800, 600, "3D Line Rotation");

    env.lines[0].start = (t_point3d){100, 100, 0};
    env.lines[0].end = (t_point3d){200, 100, 0};
    
    env.lines[1].start = (t_point3d){100, 100, 0};
    env.lines[1].end = (t_point3d){100, 200, 0};

    env.lines[2].start = (t_point3d){200, 100, 0};
    env.lines[2].end = (t_point3d){200, 200, 0};

    env.lines[3].start = (t_point3d){100, 200, 0};
    env.lines[3].end = (t_point3d){200, 200, 0};

    env.lines[4].start = (t_point3d){100, 100, 100};
    env.lines[4].end = (t_point3d){200, 100, 100};

    env.lines[5].start = (t_point3d){100, 100, 100};
    env.lines[5].end = (t_point3d){100, 200, 100};

    env.lines[6].start = (t_point3d){200, 100, 100};
    env.lines[6].end = (t_point3d){200, 200, 100};

    env.lines[7].start = (t_point3d){100, 200, 100};
    env.lines[7].end = (t_point3d){200, 200, 100};

    env.lines[8].start = (t_point3d){100, 100, 0};
    env.lines[8].end = (t_point3d){100, 100, 100};

    env.lines[9].start = (t_point3d){200, 100, 0};
    env.lines[9].end = (t_point3d){200, 100, 100};

    env.lines[10].start = (t_point3d){200, 200, 0};
    env.lines[10].end = (t_point3d){200, 200, 100};

    env.lines[11].start = (t_point3d){100, 200, 0};
    env.lines[11].end = (t_point3d){100, 200, 100};


    env.rotation_point = (t_point3d){150, 150, 50};

    env.rotation_x = 0;
    env.rotation_y = 0;
    env.rotation_z = 30;

    mlx_key_hook(env.win_ptr, key_hook, &env); // Manejar eventos de teclado

    draw_line_3d(&env); // Dibuja la línea inicial

    mlx_loop(env.mlx_ptr);
    return 0;
}


