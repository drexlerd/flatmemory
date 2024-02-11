window.BENCHMARK_DATA = {
  "lastUpdate": 1707610439097,
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
          "id": "4b84327d54946c53f7269d83f7e87d58cbab2fe3",
          "message": "switch to byte buffer",
          "timestamp": "2024-02-10T21:23:01+01:00",
          "tree_id": "e60e3bdb232ec79a342f1cc2a314c7535a747d65",
          "url": "https://github.com/drexlerd/flatmemory/commit/4b84327d54946c53f7269d83f7e87d58cbab2fe3"
        },
        "date": 1707596649776,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36835065.68421087,
            "unit": "ns/iter",
            "extra": "iterations: 19\ncpu: 36830057.89473684 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 42458894.6428567,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42458957.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 42804413.91666656,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 42803391.66666665 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 133881341.39999864,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133862740 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403183544.5000027,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399644950.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 1088368850.9999986,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 1082401899.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128232595.00000007,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128228340.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18499413.82051248,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18498430.769230783 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142818769.60000092,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142816500.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43987020.37499991,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43984350.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 336860907.99999845,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 336849699.9999992 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185990230.00000158,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 185987833.33333322 ns\nthreads: 1"
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
          "id": "7248d0c75291743092586149ac23f2e4afa7ada0",
          "message": "randomly access bitsets",
          "timestamp": "2024-02-10T00:01:01+01:00",
          "tree_id": "d508de1c89fb8f26215e6b39e8936628cae51de8",
          "url": "https://github.com/drexlerd/flatmemory/commit/7248d0c75291743092586149ac23f2e4afa7ada0"
        },
        "date": 1707608075532,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41164291.69230811,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41162723.07692308 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 65886546.7777774,
            "unit": "ns/iter",
            "extra": "iterations: 9\ncpu: 65882655.55555555 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 47929805.545454554,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 47927418.18181818 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 101006769.83333302,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 101002350.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404058840.4999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404044749.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 518295119.0000153,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 518286299.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 145697976.00000244,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145689679.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 24644146.107142717,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 24643046.428571433 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154243038.20000204,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154231500.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 58378907.27272566,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 58377209.09090915 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350889133.9999991,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350881249.9999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 201777822.6666659,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 201769466.66666675 ns\nthreads: 1"
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
          "distinct": false,
          "id": "347f18ad454fde04f5640c0625c5473322f9c998",
          "message": "another iteration",
          "timestamp": "2024-02-11T00:33:04+01:00",
          "tree_id": "1f3275955f66785da38192dc895a85235a95023e",
          "url": "https://github.com/drexlerd/flatmemory/commit/347f18ad454fde04f5640c0625c5473322f9c998"
        },
        "date": 1707608414801,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40019911.85714157,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40017085.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58685021.70000056,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58684819.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45812222.36363787,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 45810200.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95543527.57142834,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95539314.28571431 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 395957421.50000036,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394916150 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 501680027.0000203,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501650199.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129435213.80000219,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129429820 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18878617.026315603,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18878173.68421052 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 143750058.79999775,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143744020.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45877564.733333044,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45874899.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 332623509.9999906,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 332614099.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 187561767.25000274,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 187558525.00000003 ns\nthreads: 1"
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
          "id": "338d6c625dff039cc82004fb781f7bac067c124f",
          "message": "changed unit test action to debug mode",
          "timestamp": "2024-02-11T00:40:27+01:00",
          "tree_id": "1157bede19686fc131228c25fe08863fe752f397",
          "url": "https://github.com/drexlerd/flatmemory/commit/338d6c625dff039cc82004fb781f7bac067c124f"
        },
        "date": 1707608491671,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41708909.14285711,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41709171.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 61353967.40000089,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 61346949.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46585092.266667515,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46585346.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95202201.00000237,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95192600.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 421460798.99998766,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 418071649.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 500528809.9999916,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 500461600.0000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142606625.59999558,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142594300.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19981448.057143323,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19978860 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152491815.59999555,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152480499.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52968610.92857139,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 52962514.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 354591870.99999666,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 354585600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 217368268.3333311,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 217365300.00000027 ns\nthreads: 1"
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
          "id": "98b176e3acee95c4966a924ccc0a76f11c354b5f",
          "message": "added easier control for memory per segments",
          "timestamp": "2024-02-11T01:05:17+01:00",
          "tree_id": "d6b6321ec595e2d54f9ff7e2cf5ead0f02d241d3",
          "url": "https://github.com/drexlerd/flatmemory/commit/98b176e3acee95c4966a924ccc0a76f11c354b5f"
        },
        "date": 1707610035021,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42285794.08333152,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 42284616.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58136178.80000095,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58130049.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46876400.36363725,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46863790.90909093 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95154814.71428546,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95150600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 416493180.9999928,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 416467300.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 501883106.00000817,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501882200.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134230757.00000027,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134215180 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20649908.823529854,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20649252.941176485 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147312909.59999797,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147300300.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47808618.42857169,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47807135.71428568 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 344165520.9999936,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 344153549.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 215076819.99999782,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 215055066.66666698 ns\nthreads: 1"
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
          "id": "878e99d6cf9a327c8cc5faf3cc6fa30f33f05533",
          "message": "update readme",
          "timestamp": "2024-02-11T01:12:27+01:00",
          "tree_id": "93e4f13b7dcd9477238246dc36e40cff7ed28407",
          "url": "https://github.com/drexlerd/flatmemory/commit/878e99d6cf9a327c8cc5faf3cc6fa30f33f05533"
        },
        "date": 1707610438161,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40186585.07142854,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40183364.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 59805108.2000012,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 59797259.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46138897.999999136,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46137154.54545457 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95220340.71428768,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95219157.1428571 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397045328.5000133,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397029099.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 500263666.9999845,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 500246400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 137825366.0000041,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 137817820.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19214305.388888735,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19213019.444444448 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150095912.7999977,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150086560.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46096693.28571491,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46092600.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 349441272.0000071,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 349426900.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 193422526.99999562,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 193407400.00000048 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}