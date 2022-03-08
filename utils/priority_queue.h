#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <stdbool.h>
#include <string.h>

inline static void _PQSwap(void *const PQ, const size_t i1, const size_t i2, const size_t elemSize)
{
  char temp[elemSize];
  char *const pq = PQ;

  memcpy(temp, &pq[i1 * elemSize], elemSize);
  memcpy(&pq[i1 * elemSize], &pq[i2 * elemSize], elemSize);
  memcpy(&pq[i2 * elemSize], temp, elemSize);
}

inline static void _PQSwim(
    void *const PQ, const size_t index, const size_t elemSize, bool (*compare)(const void *const, const void *const))
{
  char *const pq = PQ;

  for (size_t i = index; i > 1 && compare(&pq[i / 2 * elemSize], &pq[i * elemSize]); i = i / 2) {
    _PQSwap(PQ, i / 2, i, elemSize);
  }
}

inline static void _PQSink(void *const PQ, const size_t index, const size_t end, const size_t elemSize,
    bool (*compare)(const void *const, const void *const))
{
  char *const pq = PQ;
  int temp = 0;

  for (size_t i = index; i * 2 < end + 1; i = temp) {
    temp = (i * 2 + 1 < end + 1) && compare(&pq[i * 2 * elemSize], &pq[(i * 2 + 1) * elemSize]) ? i * 2 + 1 : i * 2;

    if (compare(&pq[temp * elemSize], &pq[i * elemSize])) {
      break;
    }

    _PQSwap(PQ, i, temp, elemSize);
  }
}

inline static void *PQCreate(const size_t length, size_t *const end, const size_t elemSize)
{
  *end = 0;
  return malloc((length + 1) * elemSize);
}

inline static void PQInsert(void *const PQ, void *val, size_t *const end, const size_t elemSize,
    bool (*compare)(const void *const, const void *const))
{
  char *const pq = PQ;

  memcpy(&pq[++(*end) * elemSize], val, elemSize);
  _PQSwim(PQ, *end, elemSize, compare);
}

inline static void *PQDelete(
    void *const PQ, size_t *const end, const size_t elemSize, bool (*compare)(const void *const, const void *const))
{
  char *const pq = PQ;
  char *val = (char *)malloc(elemSize);

  memcpy(val, &pq[1 * elemSize], elemSize);
  _PQSwap(PQ, 1, *end, elemSize);
  _PQSink(PQ, 1, --(*end), elemSize, compare);

  return (void *)val;
}

#endif /* __PRIORITY_QUEUE_H__ */
