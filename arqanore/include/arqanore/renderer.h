#pragma once

#define RENDER_TARGET_FONT 0
#define RENDER_TARGET_POLYGON 1
#define RENDER_TARGET_SPRITE 2
#define RENDER_TARGET_MODEL 3

#include <cstdlib>
#include "shader.h"
#include "window.h"
#include "font.h"
#include "polygon.h"
#include "texture.h"
#include "vector2.h"
#include "vector3.h"
#include "quaternion.h"
#include "sprite.h"
#include "camera.h"
#include "matrix4.h"
#include "mesh.h"
#include "model.h"

namespace arqanore {
    class Renderer {
        friend class Window;

    private:
        static Shader *shader;
        static Shader *shader_font;
        static Shader *shader_polygon;
        static Shader *shader_sprite;
        static Shader *shader_model;

        static void reset();

        static std::string paragraph_parse_tags(std::string& text);

        static bool switch_shader(Shader *ptr);

    public:
        static Matrix4 generate_model_matrix(Vector3 pos, Quaternion rot, Vector3 scl);

        static Matrix4 generate_view_matrix(Camera &camera);

        static Matrix4 generate_projection_matrix(Camera &camera, Window *window);

        static void set_shader(Shader *ptr, unsigned int target);

        static void render_text(Window *window, Font *font, std::string text, Vector2 position, Color color);

        static void render_paragraph(Window *window, Font *font, std::string text, Vector2 position, float width, Color color);

        static void render_polygon(Window *window, Polygon *polygon, Texture *texture, Vector2 position, Vector2 scale, Vector2 origin, Vector2 offset, float angle, bool flip_hor, bool flip_vert, Color color);

        static void render_sprite(Window *window, Sprite *sprite, Vector2 position, Vector2 scale, Vector2 origin, float angle, int frame_hor, int frame_vert, bool flip_hor, bool flip_vert, Color color);

        static void render_model(Window *window, Model *model, Vector3 position, Quaternion rotation, Vector3 scale, int frame);
    };
}