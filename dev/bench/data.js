window.BENCHMARK_DATA = {
  "lastUpdate": 1707521507358,
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
          "id": "7248d0c75291743092586149ac23f2e4afa7ada0",
          "message": "randomly access bitsets",
          "timestamp": "2024-02-10T00:01:01+01:00",
          "tree_id": "d508de1c89fb8f26215e6b39e8936628cae51de8",
          "url": "https://github.com/drexlerd/flatmemory/commit/7248d0c75291743092586149ac23f2e4afa7ada0"
        },
        "date": 1707519723320,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40400283.30769238,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40399630.769230776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 64270193.90000055,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 64269730 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45782908.72727435,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 45783363.63636363 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 98704299.49999958,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 98703600.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 392729426.4999972,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 392720450.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 552747051.0000114,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 552718800.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133669046.20000355,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133668560.00000009 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18261941.34210518,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18261344.736842092 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147557284.1999963,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147557020 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44137609.71428563,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44136785.714285776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 342967959.99999577,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 342955599.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188461498.75000152,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188462949.9999999 ns\nthreads: 1"
          }
        ]
      },
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
          "id": "8ba162d48ff88650f60411cbf2f176bdefaa5073",
          "message": ".",
          "timestamp": "2024-02-10T00:30:50+01:00",
          "tree_id": "b117c6fb5f74c900750f7a557914bb2e45f4a68b",
          "url": "https://github.com/drexlerd/flatmemory/commit/8ba162d48ff88650f60411cbf2f176bdefaa5073"
        },
        "date": 1707521506874,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41060082.84615388,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41031430.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 62049756.199999705,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 62044250 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46745546.09090882,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46744518.181818195 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 98943697.4999999,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 98932549.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 421053224.4999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421028549.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 510654966.0000042,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 510604199.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136734539.59999904,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136722900 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18841281.783783633,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 18840578.378378358 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150638670.39999932,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150636420.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45129062.50000067,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45128128.571428604 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350335847.50000554,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350331650.00000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 195732914.9999983,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 195728833.33333322 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}