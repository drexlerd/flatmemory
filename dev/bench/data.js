window.BENCHMARK_DATA = {
  "lastUpdate": 1707491726332,
  "repoUrl": "https://github.com/drexlerd/flatmemory",
  "entries": {
    "Benchmark": [
      {
        "commit": {
          "author": {
            "email": "dominik.drexler@gmx.net",
            "name": "Dominik Drexler",
            "username": "drexlerd"
          },
          "committer": {
            "email": "dominik.drexler@gmx.net",
            "name": "Dominik Drexler",
            "username": "drexlerd"
          },
          "distinct": true,
          "id": "b3dbb937806830185bda1d5f77a858191e286ff6",
          "message": "added more benchmarks",
          "timestamp": "2024-02-09T16:14:10+01:00",
          "tree_id": "d5a6e2f80871b8692b037040e4697509e6431604",
          "url": "https://github.com/drexlerd/flatmemory/commit/b3dbb937806830185bda1d5f77a858191e286ff6"
        },
        "date": 1707491725963,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/1",
            "value": 3093856.008968618,
            "unit": "ns/iter",
            "extra": "iterations: 223\ncpu: 3093670.852017937 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/1",
            "value": 539526.0178571584,
            "unit": "ns/iter",
            "extra": "iterations: 1288\ncpu: 539470.8074534163 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/10",
            "value": 3934551.624999924,
            "unit": "ns/iter",
            "extra": "iterations: 176\ncpu: 3934040.340909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/10",
            "value": 687480.2920354137,
            "unit": "ns/iter",
            "extra": "iterations: 1017\ncpu: 687384.7590953788 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/100",
            "value": 40138481.764704935,
            "unit": "ns/iter",
            "extra": "iterations: 17\ncpu: 40122170.58823531 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/100",
            "value": 34786300.700000085,
            "unit": "ns/iter",
            "extra": "iterations: 20\ncpu: 34728890.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/1",
            "value": 134597.63869105405,
            "unit": "ns/iter",
            "extra": "iterations: 5195\ncpu: 134588.75842155924 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/1",
            "value": 132835.83522297666,
            "unit": "ns/iter",
            "extra": "iterations: 5292\ncpu: 132829.68631897206 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/10",
            "value": 390934.57662193466,
            "unit": "ns/iter",
            "extra": "iterations: 1788\ncpu: 390913.1431767345 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/10",
            "value": 376734.20967743127,
            "unit": "ns/iter",
            "extra": "iterations: 1860\ncpu: 376729.9999999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/100",
            "value": 4037115.4080459955,
            "unit": "ns/iter",
            "extra": "iterations: 174\ncpu: 4037132.758620694 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/100",
            "value": 3961386.045197792,
            "unit": "ns/iter",
            "extra": "iterations: 177\ncpu: 3961349.717514131 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}