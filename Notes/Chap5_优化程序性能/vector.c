#include <stdio.h>
#define SIZE 102400
#include <time.h>
typedef struct {
  int len;      // 向量长度
  float *data;  // 向量元素存储地址
} vec;

// 获取向量长度
int vec_length(vec *v) {return v->len;}

// 获取向量中下标的元素值，保存在指针参数 val 中
int get_vec_element(vec *v, size_t idx, float *val) {
  if (idx >= v->len)
    return 0;
  *val = v->data[idx];
  return 1;
}

// 求和
void vector_sum(vec *v, float *sum) {
  long i;
  *sum = 0;
  for (i = 0; i < vec_length(v); i++) {
    float val;
    get_vec_element(v, i, &val);
    *sum = *sum + val;    
  }
}

// 循环展开优化
void sum_vector_opt(vec *v, float *sum) {
  long i, len;
  float tmp, sum2 = 0;
  *sum = 0;
  len = vec_length(v);
  for (i = 0; i + 1< len; i += 2) {
    float val;
    get_vec_element(v, i, &val);
    sum2 += val;
    get_vec_element(v, i + 1, &tmp);
    *sum = *sum + tmp;
  }
  *sum += sum2;
  while (i < len) {
    get_vec_element(v, i, &tmp);
    *sum = *sum + tmp;
    i++;
  }
}

int main() {
  float data[SIZE], sum;
  // 数据初始化
  for (int i = 0; i < SIZE; i++) {
    data[i] = i * 1.324;
  }
  vec v;
  v.len = SIZE;
  v.data = data;

  clock_t start, stop;
  start = clock();
  // 调用函数计算
  // vector_sum(&v, &sum);
  sum_vector_opt(&v, &sum);
  stop = clock();
  printf("the sum is %.3f\n", sum);
  printf("the running time is %lf\n", ((double)(stop - start)));
}