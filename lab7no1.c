#include <stdio.h>

double functionM(void);
int functionN(int n, double x);
double functionO(double, int, double, int);
double functionP(int a, int n, int b, int c);

int main(void) {
    int a, b, c, d, e;
    double r, s, t, u, v;

functionM();
// ถูก: เรียกใช้ได้ปกติ (ไม่รับค่า return ก็ได้)

a = functionM();
// ถูก: return เป็น double แต่เก็บใน int ได้ (ทศนิยมถูกตัด)

b = functionN(a, b);
// ถูกแต่มี warning: b เป็น int แต่ parameter ที่ 2 ต้องเป็น double (ถูก cast อัตโนมัติ)
// และ b ยังไม่ถูกกำหนดค่า

r = functionO(r, a, s, b);
// ถูก: ชนิดข้อมูลตรงกับ prototype
// แต่ r และ s ยังไม่ถูกกำหนดค่า

s = functionP(a, b, c, d, e);
// ผิด (error): functionP รับแค่ 4 argument แต่ส่งมา 5

u = functionM();
// ถูก: double รับค่าจาก functionM ได้

c = d + functionN(r, s);
// ถูกแต่มี warning: r เป็น double แต่ parameter แรกต้องเป็น int (ทศนิยมถูกตัด)
// และ d ยังไม่ถูกกำหนดค่า

t = s * functionO(r, a, r, a);
// ถูก: argument ตรงตาม prototype

a = v + functionP(r, s, t, t);
// ถูกแต่มี warning: functionP ต้องการ int แต่ส่ง double หลายตัว (ถูกตัดทศนิยม)
// และ v ยังไม่ถูกกำหนดค่า

functionP(functionN(a, a), s, t, t+r);
// ถูกแต่มี warning: s, t, t+r เป็น double แต่ functionP ต้องการ int

v = functionP(functionN(a, a), s, t, t+r);
// ถูกแต่มี warning: เหมือนบรรทัดก่อนหน้า (double ถูก cast เป็น int)

    return 0;
}

