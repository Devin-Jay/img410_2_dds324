// DEVIN
void v3_from_points(float *dst, float *a, float *b) // form v3 from a to b
{

}

// JAKE
void v3_add(float *dst, float *a, float *b)
{

}

// DEVIN
void v3_subtract(float *dst, float *a, float *b)
{
    dst[0] = a[0] - b[0];
    dst[1] = a[1] - b[1];
    dst[2] = a[2] - b[2];
}

// JAKE
float v3_dot_product(float *a, float *b)
{
    return 0.0;
}

// DEVIN
void v3_cross_product(float *dst, float *a, float *b)
{
    dst[0] = a[1]*b[2] - a[2]*b[1];
    dst[1] = a[2]*b[0] - a[0]*b[2];
    dst[2] = a[0]*b[1] - a[1]*b[0];
}

// JAKE
void v3_scale(float *dst, float s)
{

}

// DEVIN
float v3_angle(float *a, float *b) // angle between a and b
{
    return 0.0;
}

// JAKE
float v3_angle_quick(float *a, float *b) // angle between a and b; no cos-1
{
    return 0.0;
}

// DEVIN
void v3_reflect(float *dst, float *v, float *n)
{

}

// JAKE
float v3_length(float *a)
{
    return 0.0;
}

// DEVIN
void v3_normalize(float *dst, float *a)
{
    float length = v3_length(a);
    if (length == 0.0) {
        dst[0] = 0.0;
        dst[1] = 0.0;
        dst[2] = 0.0;
        return;
    }

    dst[0] = a[0] / length;
    dst[1] = a[1] / length;
    dst[2] = a[2] / length;
}