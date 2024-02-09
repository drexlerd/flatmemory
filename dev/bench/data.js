window.BENCHMARK_DATA = {
  "lastUpdate": 1707491081061,
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
          "id": "f0f6a8038b5c599c32c8e6dc29a33a21c692845e",
          "message": "reset benchmark data",
          "timestamp": "2024-02-09T15:56:03+01:00",
          "tree_id": "fb47653c354c9733b50aa5ec1343b92e5491da6b",
          "url": "https://github.com/drexlerd/flatmemory/commit/f0f6a8038b5c599c32c8e6dc29a33a21c692845e"
        },
        "date": 1707490614793,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/10",
            "value": 3298073.8240740867,
            "unit": "ns/iter",
            "extra": "iterations: 216\ncpu: 3297802.314814815 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/10",
            "value": 444384.2534854273,
            "unit": "ns/iter",
            "extra": "iterations: 1578\ncpu: 444358.87198986067 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/10",
            "value": 663537.5946717426,
            "unit": "ns/iter",
            "extra": "iterations: 1051\ncpu: 663500.8563273074 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/10",
            "value": 375727.9645542398,
            "unit": "ns/iter",
            "extra": "iterations: 1862\ncpu: 375692.5349087002 ns\nthreads: 1"
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
          "id": "260aca0d0dddb8fdf0278ea22ceccdfe76adf5a8",
          "message": "use size() in for loop",
          "timestamp": "2024-02-09T16:03:41+01:00",
          "tree_id": "c2118856467a2c1c457cb2b5c6230759d7bc2650",
          "url": "https://github.com/drexlerd/flatmemory/commit/260aca0d0dddb8fdf0278ea22ceccdfe76adf5a8"
        },
        "date": 1707491080140,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/100000/10",
            "value": 3367671.4951457195,
            "unit": "ns/iter",
            "extra": "iterations: 206\ncpu: 3367500.485436893 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/100000/10",
            "value": 438439.572761187,
            "unit": "ns/iter",
            "extra": "iterations: 1608\ncpu: 438412.5621890545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/100000/10",
            "value": 672767.3908826411,
            "unit": "ns/iter",
            "extra": "iterations: 1031\ncpu: 672724.9272550922 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/100000/10",
            "value": 377096.61262241093,
            "unit": "ns/iter",
            "extra": "iterations: 1838\ncpu: 377084.22198041354 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}