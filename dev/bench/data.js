window.BENCHMARK_DATA = {
  "lastUpdate": 1715635047480,
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
          "id": "7db82eafc91857ee352f3248b79b35cf111a5305",
          "message": "pass segment size at runtime",
          "timestamp": "2024-02-11T12:17:32+01:00",
          "tree_id": "9ce8f3ca2a3de160c8d863fc79171ad00a9fecf0",
          "url": "https://github.com/drexlerd/flatmemory/commit/7db82eafc91857ee352f3248b79b35cf111a5305"
        },
        "date": 1707650315763,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40260377.384614594,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40255784.61538462 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 57918114.00000184,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57915672.72727272 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46070737.09090834,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46064500.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 94187137.285713,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 94176085.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 392117620.5000023,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 392099400.00000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 506154662.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 506152000.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132305825.20000097,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132296579.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18331918.578947704,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18331081.578947354 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145015537.79999766,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145002279.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44326941.499999605,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44323831.25000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 335698582.99999565,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 335670249.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 191013527.50000444,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191007399.9999997 ns\nthreads: 1"
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
          "id": "e07353bcc10fe3a3866758ec08e258d7e57a3416",
          "message": "iteration on containers",
          "timestamp": "2024-02-11T13:06:10+01:00",
          "tree_id": "41169c1c36ba339e8ea5a66dfaae5bf813c39ab5",
          "url": "https://github.com/drexlerd/flatmemory/commit/e07353bcc10fe3a3866758ec08e258d7e57a3416"
        },
        "date": 1707653229679,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38699264.692308605,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 38699107.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 55961505.54545303,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 55955690.90909092 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 44517800.99999958,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44517568.75 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 91916359.00000148,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 91906885.71428569 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 399487252.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399453699.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 484068577.4999969,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 483977149.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133298915.60000534,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133289760.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18129520.205128267,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18127671.7948718 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145344595.00000027,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145336160.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 42692374.823529385,
            "unit": "ns/iter",
            "extra": "iterations: 17\ncpu: 42691276.47058824 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 337648654.0000059,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 337646350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188297353.00000295,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188293300.0000002 ns\nthreads: 1"
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
          "id": "3736a2e094dab970108b44b30b5ab155ce80b39c",
          "message": "removed unused byte stream utils",
          "timestamp": "2024-02-11T13:09:00+01:00",
          "tree_id": "faced839cf571a9edb352b23c230f2e2ccdc0136",
          "url": "https://github.com/drexlerd/flatmemory/commit/3736a2e094dab970108b44b30b5ab155ce80b39c"
        },
        "date": 1707653409620,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40259054.46153808,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40258807.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 58318449.60000012,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 58319419.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46396975.090909176,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46385763.63636362 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 95695046.85714087,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 95696657.14285712 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 398144633.5000101,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398093300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 505193824.99999213,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 505173800.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139359076.39999527,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139352560.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21135279.685714588,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 21133382.857142866 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147424576.99999818,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147416919.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 56789755.833333306,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 56783566.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 357798977.49999636,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 357777550.00000066 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 256690892.33333388,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 256675033.33333325 ns\nthreads: 1"
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
          "id": "c3c753af8460052644fb6a0db88a2d8c839bcba2",
          "message": "rename stream to buffer",
          "timestamp": "2024-02-11T13:23:59+01:00",
          "tree_id": "a9940dad4e60ce08ac368a2dc4f5ff5bcd253850",
          "url": "https://github.com/drexlerd/flatmemory/commit/c3c753af8460052644fb6a0db88a2d8c839bcba2"
        },
        "date": 1707654305815,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41278527.785712935,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41276121.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 57750508.18181946,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57749990.90909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46505565.99999979,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 46493781.818181805 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 94329147.4285713,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 94325685.71428566 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424399340.5000026,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424344800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 504242237.99998915,
            "unit": "ns/iter",
            "extra": "iterations: 1\ncpu: 501240400.00000036 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128735128.40000102,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128735499.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18583531.184210014,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18583071.052631587 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 143087720.40000123,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143086199.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43538328.37499993,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43535337.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 333589235.4999999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 333566600.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 186738048.2499996,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 186735849.99999982 ns\nthreads: 1"
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
          "id": "51596d9cd658a91d0d3b79f59479daa684197c2e",
          "message": "buffer implementation with direct write",
          "timestamp": "2024-02-11T18:33:14+01:00",
          "tree_id": "96ae868c8dee30631689acc2e11b08688d4b8e33",
          "url": "https://github.com/drexlerd/flatmemory/commit/51596d9cd658a91d0d3b79f59479daa684197c2e"
        },
        "date": 1707672863923,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 37084241.38888944,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 37080211.11111111 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 22106733.49999981,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 22103993.750000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43264668.416667245,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 43262616.66666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 59480313.40000029,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 59469849.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397941723.0000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394308849.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 457413650.50000125,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 457384349.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131061283.60000184,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131059520.00000016 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20333053.228571072,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20332834.285714287 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146705838.20000046,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146703939.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 50116818.92307688,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 50111853.846153885 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 378077997.5000002,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 378037350.0000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 200100349.66666505,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 200081966.66666695 ns\nthreads: 1"
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
          "id": "88916156ff944e73a5d96088772caf158be2829b",
          "message": "work on setting correct buffer size",
          "timestamp": "2024-02-11T19:58:47+01:00",
          "tree_id": "099943eb0583a0ef402a16aad93cc60f28a0f938",
          "url": "https://github.com/drexlerd/flatmemory/commit/88916156ff944e73a5d96088772caf158be2829b"
        },
        "date": 1707677989377,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36685137.833333984,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 36679200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21605676.218750425,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21605806.249999993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43248421.437500186,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43245081.250000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 54691729.54545601,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 54692154.545454554 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 415337100.00000215,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 415317700.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 454979025.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452031250.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136365162.200002,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136356300.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18520964.947368298,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18520023.68421052 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152522183.0000021,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152515640.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45732255.1428559,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45729557.14285713 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 377829231.9999963,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 377799899.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 195286562.33333662,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 195280833.33333334 ns\nthreads: 1"
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
          "id": "f913438b30d0d33cb9961b51b84f923560e45e00",
          "message": ".",
          "timestamp": "2024-02-11T20:00:40+01:00",
          "tree_id": "9a828ed125d325e957adcddd9d49a36371dd2b86",
          "url": "https://github.com/drexlerd/flatmemory/commit/f913438b30d0d33cb9961b51b84f923560e45e00"
        },
        "date": 1707678096566,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 36905263.84210551,
            "unit": "ns/iter",
            "extra": "iterations: 19\ncpu: 36903410.526315786 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21547640.218749996,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21546493.749999993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 43240393.12500005,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43232856.25000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 53747049.000001185,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 53745227.272727296 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 393312082.00000846,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 393306350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 446164307.49999833,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446154500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 127630838.99999969,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 127626680.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18707336.52631585,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18696802.63157892 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145428831.59999746,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145425420.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44733452.62499961,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44732768.749999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 363366713.4999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 363352500.0000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188897291.7499956,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188895300 ns\nthreads: 1"
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
          "id": "be4eff67ad69b3d74f2ca7a257ddbb4b859380f3",
          "message": ".",
          "timestamp": "2024-02-11T20:28:47+01:00",
          "tree_id": "0111c088a684bebbd336e01775c684b4a11265d0",
          "url": "https://github.com/drexlerd/flatmemory/commit/be4eff67ad69b3d74f2ca7a257ddbb4b859380f3"
        },
        "date": 1707679791706,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 46684969.41666689,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 46685166.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21605427.49999994,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21604253.124999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53626491.10000035,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53626730 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 54919944.45454586,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 54918009.09090908 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 398961257.50000525,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398957949.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461703554.00000316,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461667550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130076163.60000043,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130074039.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19978814.48571418,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19977528.571428567 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144206213.00000107,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144203919.99999982 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48630471.35714282,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48625478.57142856 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362228494.50000185,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362228649.9999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 208623858.33333027,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 208614099.99999955 ns\nthreads: 1"
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
          "id": "4a950005ce8554d9f51ab976a3f8230b5b02d145",
          "message": "removed old byte buffer",
          "timestamp": "2024-02-11T21:33:39+01:00",
          "tree_id": "f4e6e29d1ae4c4bf0c487afc1272913aa6934c0d",
          "url": "https://github.com/drexlerd/flatmemory/commit/4a950005ce8554d9f51ab976a3f8230b5b02d145"
        },
        "date": 1707683683839,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 50279980.09090983,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 50276572.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21346209.42424297,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21346063.636363633 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 55735302.000002205,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55734679.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55740209.10000001,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55634169.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 412437229.50000006,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 411120299.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458282803.00000304,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 454821050.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 151649790.80000192,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151637800.00000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 25482557.035714544,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 25480039.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 159751773.49999824,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 159735250.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 59057604.454546265,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 59056299.99999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 413136139.4999971,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 413094800.00000054 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 242648394.33333424,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 242650666.66666672 ns\nthreads: 1"
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
          "id": "00a873ad5cf9357eef3c070bf3d99d75a8d71de2",
          "message": "removed explicit writing of padding",
          "timestamp": "2024-02-11T21:35:03+01:00",
          "tree_id": "f6995808101aa1a6977b20dc08dd217164fe7b44",
          "url": "https://github.com/drexlerd/flatmemory/commit/00a873ad5cf9357eef3c070bf3d99d75a8d71de2"
        },
        "date": 1707683763998,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47156768.16666677,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47152900 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20087870.05714266,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20087351.428571433 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53121224.09999915,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53120210.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55332039.500000015,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55329989.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 416874395.00000066,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 416839600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 448031372.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446722399.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128004818.7999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128002259.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18224503.815789573,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18221892.105263155 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142605208.80000058,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142595120.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44323018.50000009,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44321174.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 339200319.5000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 339179549.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 190507702.3333348,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 190493566.66666678 ns\nthreads: 1"
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
          "id": "4cfb617fbf5a24058ed7e6391f9444b6824abde7",
          "message": "started refactoring computation of positions, end, and alignments",
          "timestamp": "2024-02-11T21:52:35+01:00",
          "tree_id": "3e068d26a6eca946e9876202e8d5da795e6cee9a",
          "url": "https://github.com/drexlerd/flatmemory/commit/4cfb617fbf5a24058ed7e6391f9444b6824abde7"
        },
        "date": 1707684831924,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 48618427.6666665,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 48614791.66666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20140887.514285818,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20140048.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54481091.699999236,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54480439.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55154145.29999987,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55147260.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424855457.49999434,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424840400.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 451364497.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 451329950.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132621345.6000005,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132619479.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18632695.918919094,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 18631248.648648664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151950004.99999765,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151943600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44885883.28571451,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44882457.14285721 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362202887.9999988,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362197650.0000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 192009537.2499979,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191997200.0000003 ns\nthreads: 1"
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
          "id": "9e1737dd4febe1e437736860eb835c194cd30f98",
          "message": "added comments",
          "timestamp": "2024-02-11T21:57:40+01:00",
          "tree_id": "6acf9838a479861af86a3907458e37172cce1992",
          "url": "https://github.com/drexlerd/flatmemory/commit/9e1737dd4febe1e437736860eb835c194cd30f98"
        },
        "date": 1707685119660,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47310264.909090064,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 47308972.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 21323717.424242735,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21323339.393939395 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53811595.899998106,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53806429.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55396711.000000216,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55390990.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404532507.4999937,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404509800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 447878453.499996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 447862699.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135026260.6000001,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135023200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19355725.1891895,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19354518.9189189 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147418399.6000022,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147417079.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47664340.071429074,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47662392.85714287 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 358776746.00000376,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 358755449.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 198514947.74999878,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 198511499.99999994 ns\nthreads: 1"
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
          "id": "bbe5f9dd76dd062e1d662ee56a9709b2deab63b2",
          "message": "update layout computation",
          "timestamp": "2024-02-11T23:16:59+01:00",
          "tree_id": "823d7b5f476938e2da7a9a5477ff65276ad29a35",
          "url": "https://github.com/drexlerd/flatmemory/commit/bbe5f9dd76dd062e1d662ee56a9709b2deab63b2"
        },
        "date": 1707689882033,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47340359.83333366,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47337491.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20203230.885714367,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20202771.42857143 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53277943.49999948,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 53277360.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55288758.54545458,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 55282663.636363655 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 425152374.50000143,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 425126150.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 450428039.99999845,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 446878200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132185223.79999912,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132182260.00000009 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21074754.411765017,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 21074585.294117656 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144695354.60000315,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144690540.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 50283330.46153823,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 50283000.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362472510.49999815,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362439399.9999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 227517080.33333293,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 227495733.33333352 ns\nthreads: 1"
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
          "id": "b5d0bb8db8c724f6d6de30516644c9f6ffe2fea9",
          "message": "removed redundant variable",
          "timestamp": "2024-02-11T23:22:22+01:00",
          "tree_id": "5ed8eb3d909901ce7b65cc1b3dfdd8063f42ce01",
          "url": "https://github.com/drexlerd/flatmemory/commit/b5d0bb8db8c724f6d6de30516644c9f6ffe2fea9"
        },
        "date": 1707690211964,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47140060.66666817,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47139616.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20713116.617648266,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20713252.94117647 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54155717.200001165,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54153150 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 57461676.49999734,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 57460559.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 423279261.9999941,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423251700 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 452305984.9999811,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452297199.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136559775.3999964,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136560500.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22387525.25806464,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 22386919.3548387 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147764243.2000039,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147758999.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 57608322.272725135,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 57602309.09090906 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 387308277.5000114,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 387299849.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 281038752.66666967,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 281009299.9999997 ns\nthreads: 1"
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
          "id": "b8fe6384dee48a60f83e05321a9c3f0a49278761",
          "message": "added padding to tuple data",
          "timestamp": "2024-02-11T23:26:04+01:00",
          "tree_id": "15387c650c84171e0a69d76460a4af6babe654b7",
          "url": "https://github.com/drexlerd/flatmemory/commit/b8fe6384dee48a60f83e05321a9c3f0a49278761"
        },
        "date": 1707690426570,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47624378.833333485,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47609158.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20318018.62857086,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20316702.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 54500218.49999871,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 54496370.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 56369015.99999931,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 56366790 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 423647016.9999933,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423639199.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 452113206.5000017,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 452067399.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140778699.99999848,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140764400.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21169869.121212233,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21164800.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 160612564.25000182,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 160593324.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 51286598.15384559,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 51285338.46153848 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 388375094.50000596,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 388340699.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 234981955.33333424,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 234974399.99999988 ns\nthreads: 1"
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
          "id": "728f713dd4763715d1dfde1a5f1282d9e3443938",
          "message": "removed clear function",
          "timestamp": "2024-02-11T23:28:07+01:00",
          "tree_id": "a4d41c30df9c4aed33f8b4949f64577b179fdf17",
          "url": "https://github.com/drexlerd/flatmemory/commit/728f713dd4763715d1dfde1a5f1282d9e3443938"
        },
        "date": 1707690544676,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 49298909.08333334,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 49297816.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 20508730.617646955,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20507829.411764707 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 55053041.80000081,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55048390.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 55897452.80000074,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 55896430.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 425226268.4999977,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 425209850.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 448736627.9999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 448687749.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134655510.00000176,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134645060.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19549236.486486398,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19547794.5945946 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153074313.79999912,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153065400.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46373588.85714247,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46370542.85714281 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 363153848.9999997,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 363135349.9999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196889957.00000095,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 196885699.99999988 ns\nthreads: 1"
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
          "id": "bbe36f092ddf06fd3fc437e0e79fd250e06a36f6",
          "message": "separated bitset_builder and bitset_view benchmarks",
          "timestamp": "2024-02-11T23:48:25+01:00",
          "tree_id": "ee876325eb176d25d4fc242839d2d6a530733520",
          "url": "https://github.com/drexlerd/flatmemory/commit/bbe36f092ddf06fd3fc437e0e79fd250e06a36f6"
        },
        "date": 1707691775622,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 47242482.916667916,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 47241058.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 53119643.84615591,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53118815.384615384 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404165947.49999034,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404160499.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128227216.20000264,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128220380.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145084287.40000454,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145079639.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 369426680.0000037,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 369403399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27614924.692307763,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27613338.46153846 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65759124.90908887,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65754436.36363637 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456394406.00000113,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456383900.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18123257.73684171,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18123276.315789483 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44004251.3333329,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44002446.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 181621635.24999642,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 181614025 ns\nthreads: 1"
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
          "id": "8e1a2f1ba4a0f43558c528d919ea28e0b1de645e",
          "message": "added bitset functionality",
          "timestamp": "2024-02-12T00:38:45+01:00",
          "tree_id": "b991350ee451d5efec5c085daeb2dd52e097ebe2",
          "url": "https://github.com/drexlerd/flatmemory/commit/8e1a2f1ba4a0f43558c528d919ea28e0b1de645e"
        },
        "date": 1707694786752,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40751370.85714329,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40750842.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46132263.466666736,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46129253.33333335 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414520577.4999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414494249.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132355621.79999931,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132348820 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149373257.79999924,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149366299.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 372491311.4999993,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 372472500.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28319928.346153762,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 28311007.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66228916.1000004,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66225729.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456513185.5000004,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456502000.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18073277.333333347,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18072358.974358976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43666014.12499982,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43663531.25 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 182712222.74999842,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 182704900.00000006 ns\nthreads: 1"
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
          "id": "e69c4b4c73873d5bee6409915681994b0a376c80",
          "message": "made some decltype(auto) more explicit",
          "timestamp": "2024-02-12T00:43:28+01:00",
          "tree_id": "2e766e3cca2c8b231d0018c14ded5c4568466027",
          "url": "https://github.com/drexlerd/flatmemory/commit/e69c4b4c73873d5bee6409915681994b0a376c80"
        },
        "date": 1707695074882,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39263482.92857134,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39261778.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45394783.06666638,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45391726.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 417173982.50000316,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 417128699.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133383239.39999838,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133014519.99999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148599168.39999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148592260.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 377358267.5,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 377355650.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27994591.72000013,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27989767.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66318646.39999918,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66317490.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 454861682.9999972,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 454836100.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18332622.84615372,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18331561.53846154 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45021802.9999994,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45019814.28571427 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184164508.50000033,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184158449.99999997 ns\nthreads: 1"
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
          "id": "655a0406ee847b830bc69d5ba8eab17ac8fb7897",
          "message": "update readme",
          "timestamp": "2024-02-12T00:46:04+01:00",
          "tree_id": "b6ddaeec80b1c3ae69f5ac6b36c45a33ce1d0c61",
          "url": "https://github.com/drexlerd/flatmemory/commit/655a0406ee847b830bc69d5ba8eab17ac8fb7897"
        },
        "date": 1707695226293,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40036795.61538412,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40036830.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46493213.933333285,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46492506.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 396174236.00000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396158400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136578535.39999962,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136572059.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155976667.1999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155970740.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 385581784.9999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 385558349.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27670823.038461156,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27669115.384615388 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67449009.70000032,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67445270 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458179004.5000034,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 458144050 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18073519.028571434,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 18073505.714285713 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45146702.06666646,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45145800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 186550312.49999964,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 186544975.00000012 ns\nthreads: 1"
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
          "id": "d3ed8e9b27e35c926f03ac18fa9915f552415b8c",
          "message": ".",
          "timestamp": "2024-02-12T01:08:55+01:00",
          "tree_id": "e5a0964d65b07d65781d86fecbae3db6daaf6d63",
          "url": "https://github.com/drexlerd/flatmemory/commit/d3ed8e9b27e35c926f03ac18fa9915f552415b8c"
        },
        "date": 1707696610458,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39868408.857143685,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39863814.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46331981.80000022,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46330760.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414063735.5000081,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414019949.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136571341.40000266,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136557100 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153006581.50000146,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 152996825 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 389454531.50000733,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 389424700.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27656463.57692311,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27655457.692307692 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 71181904.49999985,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 71180090.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459551356.0000057,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459526550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21812143.972222015,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 21811238.88888888 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 53171314.23076769,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53169384.615384586 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 228907969.33333492,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 228890233.33333322 ns\nthreads: 1"
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
          "id": "d29b7cd15e8acbf30caad766e1639090943a2c42",
          "message": ".",
          "timestamp": "2024-02-12T01:10:45+01:00",
          "tree_id": "91a4267b2cc06750b3353fe9e9da34caaf255640",
          "url": "https://github.com/drexlerd/flatmemory/commit/d29b7cd15e8acbf30caad766e1639090943a2c42"
        },
        "date": 1707696704318,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39760209.71428592,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39757335.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45997518.53333297,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45996853.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424814219.5,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424084799.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142406870.0000021,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142396260.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156225682.99999884,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 156186324.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 401997102.99999934,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 401983099.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27499545.615384594,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27499276.923076928 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67462981.20000063,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67461880 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 456853518.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 456841649.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21470671.18749968,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21469728.12500002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52503038.53846105,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 52501646.15384614 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 228291717.6666691,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 228287966.6666669 ns\nthreads: 1"
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
          "id": "85cf1e9abd4f6fef7a479c85a88df809b8d8b8e4",
          "message": "fix to return const view from tuple",
          "timestamp": "2024-02-12T12:42:00+01:00",
          "tree_id": "9a3bf83e6b04791a832bcb478b9e0958aa42d295",
          "url": "https://github.com/drexlerd/flatmemory/commit/85cf1e9abd4f6fef7a479c85a88df809b8d8b8e4"
        },
        "date": 1707738185060,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39712808.07692123,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39710469.23076923 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45797386.60000127,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45793973.33333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 415523143.50001043,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 415486800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129582272.40000042,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129575140.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148884703.59999815,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148878900.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 368913559.0000063,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 368900800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27522599.88461521,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27520311.53846154 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66141549.63636503,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66139545.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 457171599.99999523,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 457106400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17818270.871795394,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17817541.025641024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44767051.599999756,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44766626.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 181740635.74999622,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 181737999.99999994 ns\nthreads: 1"
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
          "id": "16133ef132a6fac15103eef56276a2491e8df5be",
          "message": "fix unordered_set",
          "timestamp": "2024-02-12T12:58:33+01:00",
          "tree_id": "2a28a8d8125da2a2bb517ff6e9385765ca1ce086",
          "url": "https://github.com/drexlerd/flatmemory/commit/16133ef132a6fac15103eef56276a2491e8df5be"
        },
        "date": 1707739175617,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40230297.07142963,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40230799.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46079583.333333105,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46076373.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403849981.00000757,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403839050 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130341315.20000188,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130330100.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156545570.19999516,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 156429379.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 395207787.9999933,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395203050.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27711833.96153823,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27711242.307692304 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67428064.70000175,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67426930.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 467028857.0000025,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 467013649.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18885236.57894693,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18884565.789473675 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46993228.49999987,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 46991742.85714282 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 199482267.66666722,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 199462566.66666666 ns\nthreads: 1"
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
          "id": "05b9e59514b43004c955cfbd9b7202402349b0ec",
          "message": ".",
          "timestamp": "2024-02-12T13:20:36+01:00",
          "tree_id": "77eb27196f3e4b2d75ff8a04bc01cee1c1275465",
          "url": "https://github.com/drexlerd/flatmemory/commit/05b9e59514b43004c955cfbd9b7202402349b0ec"
        },
        "date": 1707740498109,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41470731.7142862,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41465728.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45858509.666666694,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45857626.66666665 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 407265243.49999946,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403496600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131447809.7999995,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131445160 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149605085.19999963,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149600820.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 370724885.99999785,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 370695599.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27851680.120000426,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27850188.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66018402.18181885,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66014118.18181817 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458344844.99999917,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 458324650 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17683517.27499997,
            "unit": "ns/iter",
            "extra": "iterations: 40\ncpu: 17681492.499999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43564634.87500051,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43562806.24999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 180936781.99999985,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 180924150.00000006 ns\nthreads: 1"
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
          "id": "a1b619feebb8dd1340401b12b943831dd75eb8b9",
          "message": "added back writing of padding bytes 0 to be able to easier compare and hash data based on memcmp and murmurhash",
          "timestamp": "2024-02-12T14:58:19+01:00",
          "tree_id": "1b00a9964fa0c65ef58f4f32e21487fc3b6cb4c6",
          "url": "https://github.com/drexlerd/flatmemory/commit/a1b619feebb8dd1340401b12b943831dd75eb8b9"
        },
        "date": 1707746382312,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40248118.42857088,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40247650.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45847128.666666016,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45843953.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 419330067.4999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 419294399.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133203705.59999903,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133191439.99999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151494386.59999532,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151485040.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 374493472.0000117,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 374457699.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28249079.95999979,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28249108.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66383698.69999963,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66378030 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459686999.5000077,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459682500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17821914.589743614,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17821184.615384605 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43406387.31249946,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43402712.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185112781.49999556,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185103524.99999994 ns\nthreads: 1"
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
          "id": "9459449d775ca2133d57e14a2ca2f4ad5a1a248b",
          "message": "work on interface",
          "timestamp": "2024-02-12T15:47:55+01:00",
          "tree_id": "2bc8afaa005350110941d271f313fca7b2712672",
          "url": "https://github.com/drexlerd/flatmemory/commit/9459449d775ca2133d57e14a2ca2f4ad5a1a248b"
        },
        "date": 1707749338987,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41009369.53846074,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41008176.92307693 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46260830.33333259,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46258940 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 424927809.9999998,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424907350 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136693683.20000216,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136677019.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154145042.5999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154134339.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 379207695.0000052,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 379165650 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28430257.875000346,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28430395.83333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67409480.39999922,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67408030.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 478173277.9999999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 478172300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19281539.91428628,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19281408.57142857 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47127359.69230791,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47127761.538461596 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 194823938.33333352,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 194819166.66666672 ns\nthreads: 1"
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
          "id": "e25bd5143727f33ac68035ed8fe7209e94f4fb83",
          "message": "injected hash functions into std namespace",
          "timestamp": "2024-02-12T15:54:54+01:00",
          "tree_id": "c8cbcaf98c925b1425e6f63eb9a9162af477a416",
          "url": "https://github.com/drexlerd/flatmemory/commit/e25bd5143727f33ac68035ed8fe7209e94f4fb83"
        },
        "date": 1707749763119,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42380888.35714292,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42351107.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46784999.19999979,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46785166.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 418832504.49999565,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 418792599.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140948586.79999903,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140938639.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155648441.19999748,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155641640.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 360015765.99999654,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 359994200.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28538197.76000023,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28538296 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67496393.10000077,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67489830 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461085369.49999744,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461086700.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20348071.15151521,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 20347696.969696965 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 49277867.307693034,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 49276130.769230805 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 199254076.00000253,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 199234666.66666675 ns\nthreads: 1"
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
          "id": "9d9d685e4fa014c4d7580e658068eeadaf6cbcba",
          "message": "added operator to reduce code duplication",
          "timestamp": "2024-02-12T22:41:28+01:00",
          "tree_id": "3a052f2ac8f1cfd2d0ff9b1d7cadb7e02fba403a",
          "url": "https://github.com/drexlerd/flatmemory/commit/9d9d685e4fa014c4d7580e658068eeadaf6cbcba"
        },
        "date": 1707774165381,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40093086.928571604,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40092521.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46407609.99999998,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46405280.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 414638084.00000346,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 414635250.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131483913.39999819,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131480659.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146254994.59999958,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146248220.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 341052450.0000065,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 341048500.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28279418.999999847,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28278879.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66779042.10000066,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66779380.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461976009.4999989,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461960799.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18554275.394736778,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18553250.000000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44995187.87500012,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44994331.25000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184991459.24999994,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184987550 ns\nthreads: 1"
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
          "id": "540532c12c037e74453c327c60ee8edb26c933c8",
          "message": "added working test for bitset iterator",
          "timestamp": "2024-02-13T00:22:09+01:00",
          "tree_id": "81bba60cc3113900e58911e359a9ce1bd4733fee",
          "url": "https://github.com/drexlerd/flatmemory/commit/540532c12c037e74453c327c60ee8edb26c933c8"
        },
        "date": 1707780198812,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39958241.15384913,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39957730.769230776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46254183.06666992,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46252806.666666664 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 420557035.0000016,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 420542599.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 145610866.6000091,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145606279.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 156065571.25002494,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 156055500.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 373350132.0000414,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 373332350.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28727507.720000178,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28726008.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67253228.69999672,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67250199.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 462606160.0000071,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 462609750.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21784795.677420687,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 21783751.612903222 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 53388113.6923093,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 53387638.461538464 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 248212206.3333539,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 248209500.00000003 ns\nthreads: 1"
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
          "id": "42e904f65f315c1598ed3c79d6bc7953fdeec812",
          "message": "added const",
          "timestamp": "2024-02-13T00:29:38+01:00",
          "tree_id": "74ce0cf476dd4487b62d1cb3c837b8b789303110",
          "url": "https://github.com/drexlerd/flatmemory/commit/42e904f65f315c1598ed3c79d6bc7953fdeec812"
        },
        "date": 1707780644168,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39317643.21428639,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39315435.714285724 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46106527.06666751,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46104413.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 396165112.5000003,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396090949.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135315218.40000096,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135294060.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148643598.60000035,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148638459.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 347691812.0000008,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 347675399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28260784.000000287,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28258088 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66852058.19999993,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66848950 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 463227704.00000477,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463200300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18450842.20000014,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 18448857.14285715 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45869932.92307703,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 45869061.538461566 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 187864679.24999782,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 187864700 ns\nthreads: 1"
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
          "id": "029ec72d82987dfe88d100eaac49ecfee0c1aa74",
          "message": "fix padding in tuple",
          "timestamp": "2024-02-13T00:50:01+01:00",
          "tree_id": "d8d82b79774409e6f49631aacdb2ba631c050c3a",
          "url": "https://github.com/drexlerd/flatmemory/commit/029ec72d82987dfe88d100eaac49ecfee0c1aa74"
        },
        "date": 1707781867526,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39681441.21428249,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39678728.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46557714.06666721,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46544320 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 407854129.0000146,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404622449.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 137109873.60000217,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 137103360.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150861204.19999817,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150857519.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 353597290.9999998,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 353589250.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27525174.153846767,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27523430.769230768 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66539630.81818016,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66537809.09090909 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 464080448.499999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 464023300 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17634976.435897734,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17634202.564102564 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43748599.00000061,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43747718.74999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184587118.49999076,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184576099.9999999 ns\nthreads: 1"
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
          "id": "d6f0a780ae4094e2ee2998468432175045c1eee1",
          "message": "added comment",
          "timestamp": "2024-02-13T00:50:59+01:00",
          "tree_id": "76b25fa6937d554b7c5e0af6045ac20bd676c413",
          "url": "https://github.com/drexlerd/flatmemory/commit/d6f0a780ae4094e2ee2998468432175045c1eee1"
        },
        "date": 1707781919919,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41354882.21428574,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41354192.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46511729.600000724,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46510980 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 413523718.99999696,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 413403250 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 138081528.60000008,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 138074699.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152702127.99999854,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152686800.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 358209404.0000001,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 358194150.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28270688.32000009,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28267248 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66115418.818181515,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66110600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 462090091.99999684,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 462053100.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19569840.111111365,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19569502.777777776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47552344.846153006,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47547453.84615381 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 189290297.74999863,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 189275050 ns\nthreads: 1"
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
          "id": "5bf2548f1a0f1e33deff79a2f606902434d9d896",
          "message": "factored out bitset iterator to be used by builder view and const view",
          "timestamp": "2024-02-13T14:18:38+01:00",
          "tree_id": "4e8bc2dc25824e8c66010484297f66d128d91889",
          "url": "https://github.com/drexlerd/flatmemory/commit/5bf2548f1a0f1e33deff79a2f606902434d9d896"
        },
        "date": 1707830397987,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39789585.76923202,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39790130.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46910648.53333463,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46911260.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404065172.4999975,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404051949.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142944477.0000032,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142942680 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154500129.9999953,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 154492574.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 358497973.50000757,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 358489950.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27160089.961537454,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27158634.615384612 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67973475.11110906,
            "unit": "ns/iter",
            "extra": "iterations: 9\ncpu: 67932166.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 464115287.5000074,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 464101000.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19187597.666666694,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19187086.11111111 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48008338.78571455,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48004985.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 199425836.66666755,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 199412466.66666678 ns\nthreads: 1"
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
          "id": "0317776996653c0f1e5ef2e551adab6049a76fdf",
          "message": "fix bitset iterator",
          "timestamp": "2024-02-13T20:11:24+01:00",
          "tree_id": "d6cb8d9b36b7b5e230279edddcedb54b2627e39f",
          "url": "https://github.com/drexlerd/flatmemory/commit/0317776996653c0f1e5ef2e551adab6049a76fdf"
        },
        "date": 1707851550413,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39786681.642855875,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39786428.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45853867.26666722,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45853693.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403862881.9999985,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403852200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 138578636.59999907,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 138577840.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150609234.60000026,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150606200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 352255579.00000125,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 352231350.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28174342.119999666,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28173376 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66995727.89999877,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66990660 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 463075904.0000072,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463052100.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19897532.685713973,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19895980.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46818061.46153743,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 46813884.615384646 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196647604.3333311,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 196635466.66666675 ns\nthreads: 1"
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
          "id": "25d19517c6d8de3653c9070a08f7dedf40e65665",
          "message": "improved iterator",
          "timestamp": "2024-02-13T20:45:33+01:00",
          "tree_id": "1aa4336b167002a095d79489d838867d7d8b3008",
          "url": "https://github.com/drexlerd/flatmemory/commit/25d19517c6d8de3653c9070a08f7dedf40e65665"
        },
        "date": 1707853602324,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39367473.928571425,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39365400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45757928.200000234,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45757100 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403442633.0000045,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 402572100 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132047503.39999977,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132046599.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148932171.60000062,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148924800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 351635106.4999981,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 351622849.9999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28304785.208333645,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28301637.500000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65431174.63636282,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65426945.454545446 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 461657471.0000023,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 461606300.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17925285.205128223,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17924284.615384627 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43535476.499999784,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43534224.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 187679437.2500008,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 187676350.00000006 ns\nthreads: 1"
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
          "id": "a130465812f8493984a6f912ee84ee6690997150",
          "message": "rename",
          "timestamp": "2024-02-13T20:46:23+01:00",
          "tree_id": "d637055bf008f31fa37814ac2bb4668e8561ebb2",
          "url": "https://github.com/drexlerd/flatmemory/commit/a130465812f8493984a6f912ee84ee6690997150"
        },
        "date": 1707853642564,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40325619.384615354,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40325869.23076924 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45494233.60000067,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45494533.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397337957.4999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397329800.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134406421.59999925,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134406780.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149049674.5999991,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149050079.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 349666204.99999833,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 349625199.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28459480.39999996,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28457488 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67759427.49999899,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67755720.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 460821947.49999416,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 460797700.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19195437.297297515,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19193318.918918915 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46544218.86666664,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46540386.666666634 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 191001905.00000262,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 191002600.00000003 ns\nthreads: 1"
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
          "id": "b72920cf5d8b7c263bd196dbf0f384b1f87874be",
          "message": "fixed skip zero blocks in iterator",
          "timestamp": "2024-02-13T22:09:39+01:00",
          "tree_id": "02bdf9ab627843e9d47d6bb36344eeae350dfd6e",
          "url": "https://github.com/drexlerd/flatmemory/commit/b72920cf5d8b7c263bd196dbf0f384b1f87874be"
        },
        "date": 1707858645633,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41137848.285714544,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41136421.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46945924.866666175,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46942500.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 407176220.00001085,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 407139849.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 143981551.80000457,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143959759.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154591703.59999916,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154580860.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 398955203.5000088,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398931499.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28673396.760000285,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28672420 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67273243.10000142,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67273620.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 463327217.4999945,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463213249.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20796406.166666433,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 20795908.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 55131684.53846072,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 55129084.61538463 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 259575026.33334193,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 259560366.66666666 ns\nthreads: 1"
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
          "id": "c2819d11e54284a470846ff3f7f0cf2144462281",
          "message": "remove decltype auto",
          "timestamp": "2024-02-13T22:14:28+01:00",
          "tree_id": "e1e492bef64661ff2e416a90a1bcd945e1c54298",
          "url": "https://github.com/drexlerd/flatmemory/commit/c2819d11e54284a470846ff3f7f0cf2144462281"
        },
        "date": 1707858928853,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40401331.21428572,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40400400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45416603.13333295,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45415139.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 396604011.0000009,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396569500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 125908058.59999819,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 125901580.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 141504897.40000013,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 141499140.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 331091829.99999833,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 331071849.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28475466.375000495,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28473054.166666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67144833.49999937,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67140669.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 463060919.4999948,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463019899.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17967612.820512705,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17966097.43589743 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44352273.562500596,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44351987.49999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185145877.74999925,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185133800.00000003 ns\nthreads: 1"
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
          "id": "db7ec7d0f095e5daeee144d3efc1d91b15c68a15",
          "message": "simplified setting end pos",
          "timestamp": "2024-02-13T22:20:47+01:00",
          "tree_id": "1044ab288f7b5b29c35439c0204653053424718c",
          "url": "https://github.com/drexlerd/flatmemory/commit/db7ec7d0f095e5daeee144d3efc1d91b15c68a15"
        },
        "date": 1707859311031,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40587042.35714166,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40581692.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 47974081.357143715,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47966828.57142856 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403109105.0000129,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403089599.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140285225.20000023,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140271440.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153409062.60000223,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153400460.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 354461964.500004,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 354445300.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27804872.23076897,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27804053.846153848 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66073335.49999907,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66072919.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459338024.0000045,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459332450 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17632349.97435913,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17632174.358974364 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44997800.00000036,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44997614.285714254 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185869729.2500011,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185860749.9999998 ns\nthreads: 1"
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
          "id": "a1fb419a24c46753c59e8960b2c3b986a2069e01",
          "message": "update readme",
          "timestamp": "2024-02-13T22:29:01+01:00",
          "tree_id": "9b5a6c5d545299336c4430f06a039d02795b7e19",
          "url": "https://github.com/drexlerd/flatmemory/commit/a1fb419a24c46753c59e8960b2c3b986a2069e01"
        },
        "date": 1707859801946,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40909487.3076922,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40909892.30769232 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45960764.60000043,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45960053.33333335 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 402224309.49999934,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 402198850 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 143455519.5999991,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143450399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154763721.00000048,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154755039.99999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 380893255.4999984,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 380876499.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28127139.64000011,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28125016 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67284685.90000035,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67278850 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 464142667.0000044,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 464117299.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21427328.000000134,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21426787.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 56170645.33333268,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 56164441.66666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 207495617.3333362,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 207476200.00000003 ns\nthreads: 1"
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
          "id": "7427cf1adc43bda5c5b5270d9e56dd7f982b4187",
          "message": "update readme",
          "timestamp": "2024-02-13T22:30:30+01:00",
          "tree_id": "47443f2b614fc4ffd4f80405d81b09caa6246024",
          "url": "https://github.com/drexlerd/flatmemory/commit/7427cf1adc43bda5c5b5270d9e56dd7f982b4187"
        },
        "date": 1707859891867,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39670671.142856814,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39670671.428571425 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46515070.26666669,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46515059.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 400974798.49999475,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 400964600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131514450.99999818,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131507599.99999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145512106.39999965,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145510179.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 341147689.99999964,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 341100949.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28441098.799999624,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28440503.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66755918.700000905,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66751770.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459709220.99999714,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459689750.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19499318.472221933,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19497091.666666675 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46100102.46666624,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46096873.33333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 190002851.25000006,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 189989350.00000006 ns\nthreads: 1"
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
          "id": "43bdc5ccf18d4cec7619e4df6807959b43c56b5b",
          "message": "update readme",
          "timestamp": "2024-02-13T22:37:58+01:00",
          "tree_id": "9c5f36396cf226941aa4df8a44bce5381324c8a5",
          "url": "https://github.com/drexlerd/flatmemory/commit/43bdc5ccf18d4cec7619e4df6807959b43c56b5b"
        },
        "date": 1707860338989,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41884464.142857574,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41883578.57142858 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46563977.80000058,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46560333.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 395666338.500007,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395635600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 138527961.40000123,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 138516040.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150223059.6000004,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150219099.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 361269520.99999696,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 361245099.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27780978.75999947,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27779112 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66581346.00000097,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66574549.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 462165002.50000083,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 462146799.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18146340.736842304,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18145552.631578963 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45331559.28571375,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45330064.285714276 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 189881538.50000346,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 189870924.9999999 ns\nthreads: 1"
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
          "id": "f53ac248e03174f0b5de0a768d8d17e10b1171ae",
          "message": "removed some dead codeo",
          "timestamp": "2024-02-13T22:50:07+01:00",
          "tree_id": "e877644b423b02a1cdd829e59ac84fadc1d5043b",
          "url": "https://github.com/drexlerd/flatmemory/commit/f53ac248e03174f0b5de0a768d8d17e10b1171ae"
        },
        "date": 1707861078087,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40290430.49999968,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40290228.57142858 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 47331898.33333426,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 47322980.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 399924793.4999914,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399891499.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 141902524.40000108,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 141883300.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153700128.20000058,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153689839.99999982 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 378419467.00000054,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 378410849.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27281397.461538203,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27279653.84615384 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67596759.89999892,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67592580.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 466358139.00000757,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463512999.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 23029305.61290392,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 23027867.741935477 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 54562736.153846234,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 54560199.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 203982010.66667333,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 203970333.33333337 ns\nthreads: 1"
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
          "id": "3a0e5f80943844985cabe9971c6047d7b5d6c555",
          "message": "update readme",
          "timestamp": "2024-02-13T22:58:48+01:00",
          "tree_id": "34bb8921d6952121105b42842b1b7ff29b966619",
          "url": "https://github.com/drexlerd/flatmemory/commit/3a0e5f80943844985cabe9971c6047d7b5d6c555"
        },
        "date": 1707861590726,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39843991.35714309,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39843892.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45511441.266666,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45508953.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397948248.50000054,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397937000 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136735362.79999894,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136732419.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154019422.5999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 154001979.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 357076908.5000052,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 357068249.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28754634.919999942,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28753836 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65827288.81818154,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65821318.181818195 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 463026653,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 463015599.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19811114.9166667,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19810752.777777784 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48492989.07143001,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48490357.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 189704336.33333528,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 189693833.3333334 ns\nthreads: 1"
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
          "id": "7bb26540731fe307554e88113a8e62e4667a27a4",
          "message": "update readme",
          "timestamp": "2024-02-13T23:01:09+01:00",
          "tree_id": "f9ca5767c16b7bcd0ad2774289664b6c23cd7380",
          "url": "https://github.com/drexlerd/flatmemory/commit/7bb26540731fe307554e88113a8e62e4667a27a4"
        },
        "date": 1707861733725,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40768980.142857455,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40768392.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46345043.20000019,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46336786.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 399599873.5000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399602950 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139111631.80000016,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139108539.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152047989.19999975,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152048920 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 361621123.9999956,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 361617200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28546674.840000037,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28542971.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66281446.8999997,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66276710 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 462591295.00000286,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 462486949.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18894128.342105214,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18892584.210526317 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45108066.866666265,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45107566.66666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 195955202.33333257,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 195950400.0000001 ns\nthreads: 1"
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
          "id": "7e1010475ddd17f7d9f6439441aaeeaa2bf1c1e0",
          "message": "update readme",
          "timestamp": "2024-02-13T23:02:38+01:00",
          "tree_id": "0e0ccc59b01922d72619ac3e73f23e018bc762ba",
          "url": "https://github.com/drexlerd/flatmemory/commit/7e1010475ddd17f7d9f6439441aaeeaa2bf1c1e0"
        },
        "date": 1707861821134,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38975250.21428448,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 38974092.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45534232.39999953,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45532720 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 397496424.50001943,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397400950.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129492959.59999745,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129490179.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146268739.99999362,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146262760.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 340132506.49999803,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 340130099.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28137846.80000026,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28136356.000000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66597836.00000227,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66592918.181818195 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 460188181.999996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 460155850.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18603447.131579887,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18602994.7368421 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44255307.333332896,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44252839.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188478940.9999996,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188472700.00000015 ns\nthreads: 1"
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
          "id": "4b99b974595d1119aefcfecf0e910e215d8b369f",
          "message": "added more api to insert view and constview to containers",
          "timestamp": "2024-02-13T23:20:00+01:00",
          "tree_id": "08f9e231cbcbe397f095636fab0c35c1c45c2406",
          "url": "https://github.com/drexlerd/flatmemory/commit/4b99b974595d1119aefcfecf0e910e215d8b369f"
        },
        "date": 1707862868583,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39593393.00000002,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39593857.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46661620.7999986,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46660413.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404584601.5000052,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404548850.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132425372.00000015,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132423360.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147636066.6000005,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147633380.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 345440679.9999958,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 345420550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28533298.1199997,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28532816 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67336638.59999979,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67329709.99999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459933345.9999997,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459902650.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18230852.923076887,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 18230002.564102553 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45107290.812500976,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 45103899.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184598556.25000188,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184587899.9999999 ns\nthreads: 1"
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
          "id": "67a0c4dd775a8c88fe59851e1c1e333248a5c77e",
          "message": "refactoring of bitset",
          "timestamp": "2024-02-14T12:13:56+01:00",
          "tree_id": "e501a769f4e8c58f843947d44d1687220dc9cfa5",
          "url": "https://github.com/drexlerd/flatmemory/commit/67a0c4dd775a8c88fe59851e1c1e333248a5c77e"
        },
        "date": 1707909300177,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40778154.22222228,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 40775416.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45887911.933332734,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45885953.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 402210679.0000066,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 402175600.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130531048.9999954,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130524000.00000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150230246.60000032,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150221819.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 355720524.00000584,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 355717949.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28316385.15999998,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28316264 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65971820.699999735,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 65972250.00000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 458932918.00000215,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 458928050.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17696608.179486852,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17694969.230769224 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43602635.37500053,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43600156.25000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184818921.50000334,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184809999.9999999 ns\nthreads: 1"
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
          "id": "c2abe913b0cfe23235691da8e91f7a8d58349f4a",
          "message": "bitset next_set_bit based on log2 that works",
          "timestamp": "2024-02-14T13:01:08+01:00",
          "tree_id": "1299b8b55dbb1235c5a39ada3f438674cb4ba8e3",
          "url": "https://github.com/drexlerd/flatmemory/commit/c2abe913b0cfe23235691da8e91f7a8d58349f4a"
        },
        "date": 1707912140485,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39746342.692307755,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39743707.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 48316415.866668195,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 48315240 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404533417.99999976,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404109750.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139067074.60000122,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139061580 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153233403.2499989,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 153231399.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 365085139.4999961,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 365064900.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28213711.439999543,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28209656 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67604640.99999979,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67599610.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459833701.5000027,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459783550.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 23862419.67741948,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 23860519.3548387 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 58031749.66666802,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 58026433.333333276 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 279773664.6666635,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 279737233.3333333 ns\nthreads: 1"
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
          "id": "d491e5132f66e39b37e251f47a7c0407212433ad",
          "message": "use std::bit_width",
          "timestamp": "2024-02-14T14:19:46+01:00",
          "tree_id": "7e38ff7ce9de7c517f886306b912eeab4579d457",
          "url": "https://github.com/drexlerd/flatmemory/commit/d491e5132f66e39b37e251f47a7c0407212433ad"
        },
        "date": 1707916857748,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40055832.71428646,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40053664.28571429 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46125316.46666677,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46120813.333333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 400222606.5000016,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 400184850.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139388829.00000066,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139376240 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152015409.8000006,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151994620.00000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 381531715.499996,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 381491249.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29568550.916666325,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29566079.16666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68028388.0999994,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68025050.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 466811384.99999976,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 466791800 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22684452.193548426,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 22683525.806451596 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 56887783.58333243,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 56881816.66666662 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 277901855.9999997,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 277876800.00000006 ns\nthreads: 1"
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
          "id": "5bc01ac429c3128b806f7a4df36a780c09030088",
          "message": "update value type",
          "timestamp": "2024-02-14T14:23:02+01:00",
          "tree_id": "e5087a73b569ad8a37ab9e5ef8f6c70f6110c9c2",
          "url": "https://github.com/drexlerd/flatmemory/commit/5bc01ac429c3128b806f7a4df36a780c09030088"
        },
        "date": 1707917043568,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39477565.53846204,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39477269.23076923 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46216557.73333278,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46215200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 395940532.0000045,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395916250.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 137378700.79999936,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 137377579.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 150413524.00000107,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150409200 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 352446169.4999985,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 352435150.00000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28638607.279999632,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28638327.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67798832.79999979,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67792710 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 460796848.0000011,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 460794399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18597418.861111473,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 18596297.222222224 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48465865.00000045,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 48464699.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196707552.00000182,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 196693200.00000003 ns\nthreads: 1"
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
          "id": "34cd752396335f226296ec896f81e6e4db956891",
          "message": ".",
          "timestamp": "2024-02-15T10:29:42+01:00",
          "tree_id": "94dfbc1b392fff9bc5a890efcb65ff89d95184e3",
          "url": "https://github.com/drexlerd/flatmemory/commit/34cd752396335f226296ec896f81e6e4db956891"
        },
        "date": 1707989444932,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40251045.33333332,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 40250444.44444444 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45480726.600000784,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45474619.99999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 401575483.4999967,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 401558700.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131327456.20000038,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131323059.99999988 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152326311.0000016,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152320780.00000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 347924921.4999953,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 347913450.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28269003.839999415,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28265999.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65175142.18181863,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65172590.90909092 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 459861000.00000364,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 459824499.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17489050.025641263,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17487897.435897432 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 42900707.56250053,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 42895368.74999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185266891.750004,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185245974.99999994 ns\nthreads: 1"
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
          "id": "69db46c4a36a88d1552f28d0426515be1bc287bd",
          "message": "improved vector performance",
          "timestamp": "2024-02-16T21:31:39+01:00",
          "tree_id": "3a3323daced3fe65a92e5fd7a08f2806c8f851c5",
          "url": "https://github.com/drexlerd/flatmemory/commit/69db46c4a36a88d1552f28d0426515be1bc287bd"
        },
        "date": 1708115562494,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39263549.642858006,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39262992.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46245206.06666541,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46242420.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 401290127.9999994,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 401268199.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135555823.99999934,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135553059.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145627568.20000118,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145624600.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 355521179.0000072,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 355507400 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28596438.79999908,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28595891.999999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64747956.90909281,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64732209.0909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 398724776.9999982,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398710300.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21476649.606060244,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21476206.060606062 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52113606.23076845,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 52111215.38461539 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 245959693.33333302,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 245952099.9999999 ns\nthreads: 1"
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
          "id": "08c9779e683f3c7a38f69182a9146e65fb4a014a",
          "message": "added missing writing of padding for tuple offset",
          "timestamp": "2024-02-16T21:44:05+01:00",
          "tree_id": "15cef84370ac0df132b2740b4d51a11570fad948",
          "url": "https://github.com/drexlerd/flatmemory/commit/08c9779e683f3c7a38f69182a9146e65fb4a014a"
        },
        "date": 1708116316302,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40603243.21428611,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40601428.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 47175937.42857166,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47172714.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 405935845.5000037,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 405899999.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 149095795.20000023,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149081079.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 159974628.25000143,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 159955824.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 380611346.99999857,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 380565799.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27179453.92307705,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27179142.307692308 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64031844.63636339,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64030345.45454547 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 398408294.50000113,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398383000.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22310856.27272736,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 22309551.515151523 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52098083.384615496,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 52097330.76923079 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 236414940.00000307,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 236404299.9999999 ns\nthreads: 1"
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
          "id": "bc665926f1b7f6f4118d368136f359417a2dc552",
          "message": "ensure correct buffer size type is written",
          "timestamp": "2024-02-16T22:00:18+01:00",
          "tree_id": "fad979146d5ceec7779cbf4e2d433b266c30bf40",
          "url": "https://github.com/drexlerd/flatmemory/commit/bc665926f1b7f6f4118d368136f359417a2dc552"
        },
        "date": 1708117287299,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42953632.92307723,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 42947161.53846155 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 48563364.857143044,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48555978.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 409946863.50000364,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 409921299.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 150292860.60000116,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 150279880.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 162966093.00000143,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 162540474.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 437256067.99999636,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437242299.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26930192.3846153,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26926503.846153848 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65037043.90909155,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65031109.09090907 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 402066474.0000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 402024050.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 25360559.962962795,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 25357333.33333332 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 64115076.000000216,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 64107249.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 298582748.9999977,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 298578100.0000003 ns\nthreads: 1"
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
          "id": "9a9d6710dddc8924ae27ba7f4859c30aeabd6f34",
          "message": "extended example",
          "timestamp": "2024-02-18T12:28:50+01:00",
          "tree_id": "68a036931fb159e41e954fb7319628205ff102be",
          "url": "https://github.com/drexlerd/flatmemory/commit/9a9d6710dddc8924ae27ba7f4859c30aeabd6f34"
        },
        "date": 1708255815374,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39505246.4999992,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39504007.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45637902.07142862,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45634728.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 396733290.9999968,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396706850.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134466998.19999993,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134461199.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147806225.0000022,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147800960 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 347367871.000003,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 347358199.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26410089.5555554,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 26408785.185185187 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62064752.3636367,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62062281.81818182 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396160463.49999577,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396106050 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19688849.472222123,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19688352.77777778 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47265670.23077057,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47262107.6923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 193472646.25000092,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 193464649.9999999 ns\nthreads: 1"
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
          "id": "1426e613f9f425705947a3c79587cba94b9e4fdd",
          "message": "update readme",
          "timestamp": "2024-02-18T12:30:20+01:00",
          "tree_id": "32d284efc635179e7bec3371a4df7fa3be3598b0",
          "url": "https://github.com/drexlerd/flatmemory/commit/1426e613f9f425705947a3c79587cba94b9e4fdd"
        },
        "date": 1708255878705,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38931885.88888879,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 38928244.44444445 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45540307.00000074,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45538219.999999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 395838918.9999991,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395816500 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 126996850.83333634,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 126990566.66666679 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142696311.39999887,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142683719.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 336108506.4999969,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 335955650.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26434119.333333474,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 26434251.85185185 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62309322.72727459,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62304827.27272728 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 394376850.0000004,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394371849.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17884654.820513118,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17883243.589743588 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43256959.437499635,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43256568.75 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184434278.4999995,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184431724.99999982 ns\nthreads: 1"
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
          "id": "ec63739bb9a29ea8f27c82b7e8de006e4916a973",
          "message": "added get for bitset view and constview",
          "timestamp": "2024-02-23T22:11:05+01:00",
          "tree_id": "ffc5558eaf6467f25692ee8511d42de03d722406",
          "url": "https://github.com/drexlerd/flatmemory/commit/ec63739bb9a29ea8f27c82b7e8de006e4916a973"
        },
        "date": 1708722744739,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39947185.85714249,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39944635.71428572 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46538028.266666256,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46536166.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 403991736.00000185,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403985449.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142441629.00000104,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142436820 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 157488780.40000135,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 157482120.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 354052812.5000009,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 354027950.0000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26913528.307692155,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26909338.461538468 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 61835133.45454566,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 61833136.363636374 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396038399.50000006,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396014650.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21805935.09090925,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 21804478.78787879 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47096226.153846905,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47095100.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 192500719.66666365,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 192484399.99999997 ns\nthreads: 1"
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
          "id": "f11667001ab40644ade97c98ea7b423f521f972b",
          "message": "added assert",
          "timestamp": "2024-02-23T22:12:25+01:00",
          "tree_id": "0313c95f2ee3841edab2545e87883d739ca84b23",
          "url": "https://github.com/drexlerd/flatmemory/commit/f11667001ab40644ade97c98ea7b423f521f972b"
        },
        "date": 1708722806624,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39555927.50000076,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 39552600 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 45249867.33333283,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45247946.66666668 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 393992337.00000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 393836349.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131091165.40000515,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131087520 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 141988408.200001,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 141985120 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 341763110.00000226,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 341753599.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26863681.07692243,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26862188.46153846 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62163527.909089826,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62163872.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 394961533.99998945,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394909699.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19480779.499999434,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 19479582.352941178 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47224239.06666601,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 47219593.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 204584537.9999965,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 204582333.33333334 ns\nthreads: 1"
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
          "id": "02f746095ad816f31cd16e129d7e068aac969f2c",
          "message": "added implicit conversion from view to constview",
          "timestamp": "2024-03-03T17:11:05+01:00",
          "tree_id": "531f6e1e0bc1e6307f7f056018434f8f0bab096a",
          "url": "https://github.com/drexlerd/flatmemory/commit/02f746095ad816f31cd16e129d7e068aac969f2c"
        },
        "date": 1709482347159,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42374065.92857188,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42366014.28571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 46160529.26666612,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46156648.4 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 401282905.4999969,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 401246832 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 133409791.79999976,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 133395263.60000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149013552.2000003,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148995084.4000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 338200254.0000002,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 338199643.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26476734.00000022,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 26476266.518518515 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68416441.09999834,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68412409.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 397022282.0000089,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 397001536.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20051346.394736633,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 20050708.631578952 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52596974.85714453,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 52597014.64285715 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 272033645.00000757,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 272013354.4999999 ns\nthreads: 1"
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
          "id": "f575824af293e5cd5a3425dda706c53412685bd4",
          "message": "added is_supseteq and are_disjoint to bitset",
          "timestamp": "2024-03-03T21:03:33+01:00",
          "tree_id": "533bfd551243cc59347f56b0e7a6a7f975ffb506",
          "url": "https://github.com/drexlerd/flatmemory/commit/f575824af293e5cd5a3425dda706c53412685bd4"
        },
        "date": 1709496297405,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41099633.384614155,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41092974.76923077 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 48280288.42856976,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48268415.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 418900733.00000095,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 418877815.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 145307666.79999942,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145303643.80000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 165121140.250001,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 165107869.2500001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 372529385.4999876,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 372489588.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26767117.26923031,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26766173.07692308 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63732331.63636304,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63730296.545454554 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 403070598.99998873,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403060401.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19660666.74285766,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19658436.457142856 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48080148.99999937,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 48078642.92307698 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 198375969.00000182,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 198358342 ns\nthreads: 1"
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
          "id": "39ff2cd31b489a625e671e420d6c259dd40ee6f2",
          "message": "added missing is same block concept check in new bitset operations",
          "timestamp": "2024-03-03T21:15:58+01:00",
          "tree_id": "5e5d3d7ccc15bfcec1397e8950f3838f3480f992",
          "url": "https://github.com/drexlerd/flatmemory/commit/39ff2cd31b489a625e671e420d6c259dd40ee6f2"
        },
        "date": 1709497030871,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40553220.23076804,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40550826.07692307 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 48418240.06666684,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 48413081.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 404572716.0000041,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 404531074.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 151837767.7999979,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151823815.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 161940538.74999526,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 161925500.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 403022496.50000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 403012830.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27463614.640000746,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27463068.680000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64863904.090910554,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64862586.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 399739234.4999895,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399718411.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21492405.699999988,
            "unit": "ns/iter",
            "extra": "iterations: 30\ncpu: 21491446.433333326 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 51010761.69230641,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 51008734.76923073 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 243973686.66666353,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 243958158.33333322 ns\nthreads: 1"
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
          "id": "f72acad1113c2be03524838554df6cadb3b8b0c1",
          "message": "update bitset",
          "timestamp": "2024-03-04T11:36:14+01:00",
          "tree_id": "59a1c0a34400ed9d124b92d07410241d9c9ed5ab",
          "url": "https://github.com/drexlerd/flatmemory/commit/f72acad1113c2be03524838554df6cadb3b8b0c1"
        },
        "date": 1709548635164,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42736836.15384873,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 42729557 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 48494592.53333256,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 48483460.6 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 406239479.0000212,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 406218390.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142079601.00000036,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142063307.80000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153792693.20000046,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153784959.80000013 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 370172713.50001127,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 370141216.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26818922.807690956,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26818804.11538462 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64345181.18182227,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64337229.454545476 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 398062992.50000167,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 398047001.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21347754.000000663,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 21346800.812499996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48656531.30769067,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 48647356.23076928 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 217512624.3333428,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 217511144.66666678 ns\nthreads: 1"
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
          "id": "2630f9d7a44b91ad7dbe2bbbcc4dde2be6d8bf05",
          "message": "fix default constructor bitset",
          "timestamp": "2024-03-05T14:23:08+01:00",
          "tree_id": "37d320b5388cafcfff2dd7d399800fbfad335846",
          "url": "https://github.com/drexlerd/flatmemory/commit/2630f9d7a44b91ad7dbe2bbbcc4dde2be6d8bf05"
        },
        "date": 1709645065024,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40313981.92307734,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40313367.84615385 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66838506.49999954,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66837792.20000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 445835858.4999971,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 445815114.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134328427.20000052,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134327562.80000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147982276.4000005,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147977533.99999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 357749059.5000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 357722247.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28586932.759999968,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28587222.399999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64674114.27272845,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64671965.81818182 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 400570348.50000405,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 400563882.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19338355.666666884,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19337535.27777777 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45576027.133333236,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45572879.59999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 194747336.0000013,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 194748902.33333337 ns\nthreads: 1"
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
          "id": "f3370213f1c47c5b7edb37b4a3e4e53b35e65630",
          "message": "with prints in case of further errors",
          "timestamp": "2024-03-05T23:20:30+01:00",
          "tree_id": "4d71f46f725879d2c39a2c75d254eb951f768d45",
          "url": "https://github.com/drexlerd/flatmemory/commit/f3370213f1c47c5b7edb37b4a3e4e53b35e65630"
        },
        "date": 1709677296183,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38630316.07142732,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 38625050.14285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 72597525.85714199,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 72596612.57142858 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437827952.9999816,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437817320.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128879971.20000136,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128870664.20000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144494791.20000887,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144492027.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 342227464.49998456,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 342216964.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 24978729.678571604,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 24978361.89285714 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62005537.27272894,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62003810.9090909 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 390848298.50000346,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 390829316.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17262746.049999576,
            "unit": "ns/iter",
            "extra": "iterations: 40\ncpu: 17262176.15 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 42768506.2500025,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 42768074.937500015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 180295231.7499944,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 180288080.2500002 ns\nthreads: 1"
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
          "id": "c771f78b308b70649615b62b953ebc1028d1f2ef",
          "message": "removed prints in code",
          "timestamp": "2024-03-05T23:23:02+01:00",
          "tree_id": "cda24341db756dd7cdce8aaa18dfb0e6fb65c906",
          "url": "https://github.com/drexlerd/flatmemory/commit/c771f78b308b70649615b62b953ebc1028d1f2ef"
        },
        "date": 1709677444149,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42029677.7142864,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 42012660.357142866 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66064340.59999628,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66063587.80000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 438525715.9999867,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 438485925.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131855289.19999568,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131850862.20000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 142360646.80000025,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142355837.3999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 333106401.5000038,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 333064800.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28341903.840000667,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28341094 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63054604.909087755,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63051100.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 395190584.4999999,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395179576.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19336118.444444295,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19334263.194444448 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44709222.33333189,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44708627.33333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 191834674.00000608,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191825089.99999982 ns\nthreads: 1"
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
          "id": "cc2f44408d8fabf7843b731205d5ccf90de0664c",
          "message": "update unorderedset",
          "timestamp": "2024-03-06T19:31:51+01:00",
          "tree_id": "275f1d41b560ddd76335efd124483b169614d4c7",
          "url": "https://github.com/drexlerd/flatmemory/commit/cc2f44408d8fabf7843b731205d5ccf90de0664c"
        },
        "date": 1709749989082,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40954138.30769263,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40951993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 71148335.60000023,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 71147220.6 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 442910282.50000155,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 442900765.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 143732131.00000158,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143732185 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155839607.80000156,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155839739.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 362513578.49999976,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 362500239.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26392112.074073862,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 26390049.296296295 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63315724.90908983,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63312175.54545453 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396539617.9999985,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396530844.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18729342.55263166,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18727030.526315786 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45980678.571428,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45978914.07142856 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 190747520.24999952,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 190740396.7500001 ns\nthreads: 1"
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
          "id": "bcd47fbaf60b031cb5dc84fde6dae7bc3d3e4618",
          "message": "removed resize in operator[] const of FixedSizedTypeVector",
          "timestamp": "2024-03-08T21:24:11+01:00",
          "tree_id": "fdf101d4acaca7c2201991a71de3b29ea1d81cec",
          "url": "https://github.com/drexlerd/flatmemory/commit/bcd47fbaf60b031cb5dc84fde6dae7bc3d3e4618"
        },
        "date": 1709929532491,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 42502705.07692186,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 42498193 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67055544.50000477,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67039368.000000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 440029265.99998206,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 439932939.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 131559860.20000227,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 131552008.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148022489.79999605,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148017535.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 337658216.99998355,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 337645062 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 25903569.9285712,
            "unit": "ns/iter",
            "extra": "iterations: 28\ncpu: 25900601.60714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62745769.18181909,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62741558.0909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396564863.00000894,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396531087.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18567478.138887987,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 18565305.69444444 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44655286.43750005,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 44649342.749999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 193234965.7499941,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 193226619.25000006 ns\nthreads: 1"
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
          "id": "2ff4f414343b588c29659a6684e104dd56c6b34c",
          "message": "added vector build clear",
          "timestamp": "2024-03-09T10:08:15+01:00",
          "tree_id": "36e34ba4bf8648b7b1173cc06b34b5c8f44447ff",
          "url": "https://github.com/drexlerd/flatmemory/commit/2ff4f414343b588c29659a6684e104dd56c6b34c"
        },
        "date": 1709975358055,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39431097.64285729,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39429236.214285724 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67144844.40000063,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67139012.79999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 441774244.50000304,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 441730332.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132983065.99999991,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132971432.20000009 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152410380.3999992,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 152402248.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 351431620.50000143,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 351421263.50000024 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28520438.479999937,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28512711.84 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63744230.99999986,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63742667.81818183 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 395635184.9999962,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395607105.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21581246.323529344,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 21579814.588235285 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48273442.84615374,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 48271068.84615381 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 186466524.66667035,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 186457520.33333334 ns\nthreads: 1"
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
          "id": "92f3773d84f17160426c0bf8a6d4279139f596c4",
          "message": "reformat includes added clang format",
          "timestamp": "2024-03-09T22:19:16+01:00",
          "tree_id": "e41cfc203e3f50a489a50a9aa05e999526cc18ae",
          "url": "https://github.com/drexlerd/flatmemory/commit/92f3773d84f17160426c0bf8a6d4279139f596c4"
        },
        "date": 1710019224308,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40786641.69230706,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40784664.61538462 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67198916.99999891,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67192816.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 445105935.00000083,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 445034839.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134709280.200002,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134688301.59999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148909881.19999522,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148906181.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 346062420.5000045,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 346033566.99999964 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26097682.592592265,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 26095305.407407407 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63593468.18181744,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63589476.0909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 394769322.49999666,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394745710.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19139490.714285657,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19137572.485714294 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47666235.07142802,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47661302.07142855 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 205967659.33333924,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 205959813.66666678 ns\nthreads: 1"
          }
        ]
      },
      {
        "commit": {
          "author": {
            "email": "simon.stahlberg@gmail.com",
            "name": "Simon",
            "username": "simon-stahlberg"
          },
          "committer": {
            "email": "simon.stahlberg@gmail.com",
            "name": "Simon",
            "username": "simon-stahlberg"
          },
          "distinct": true,
          "id": "2bbbb52430e6b200ef6ee997eafc371f847cebf0",
          "message": "Fix Clang warnings and errors",
          "timestamp": "2024-03-15T11:10:00+01:00",
          "tree_id": "623f20b69921a67e3228c633cf0df2dfaba7a94c",
          "url": "https://github.com/drexlerd/flatmemory/commit/2bbbb52430e6b200ef6ee997eafc371f847cebf0"
        },
        "date": 1710497459087,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40123741.071428955,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40122867.07142858 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 69482673.59999959,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 69479090.50000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 443317546.50000477,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 443292458.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139774663.60000223,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139771301.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 158783531.80000034,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 158769301.20000008 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 354770579.00000376,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 354763221.5000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28572983.720000025,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28569677.319999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63650506.09091001,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63648837.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 395599396.0000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395566408.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19898817.400000114,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 19897461.942857143 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47318184.00000013,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 47315066.35714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 202684266.00000092,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 202665855.33333328 ns\nthreads: 1"
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
          "id": "bfd510bd8accbe4966b24cbd88d78807df428875",
          "message": "split types from type traits",
          "timestamp": "2024-03-16T13:00:53+01:00",
          "tree_id": "950c7bdcf18d547c308431383eb2e8ae7b005ecd",
          "url": "https://github.com/drexlerd/flatmemory/commit/bfd510bd8accbe4966b24cbd88d78807df428875"
        },
        "date": 1710590517230,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39609782.14285709,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39603325.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66819329.00000024,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66813956.63636363 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437277266.50000423,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437240928 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135433956.40000427,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135430785.79999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151514037.79999554,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151505407.4 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 349737550.0000004,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 349721114.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28578093.92000036,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28574802.440000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 62867909.81818058,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 62855824.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 399709581.49999094,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 399695848.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18923731.86486517,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 18922037.243243244 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45918449.13333413,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 45914648.46666665 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196449241.4999981,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 196435807.49999988 ns\nthreads: 1"
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
          "id": "97d26c584cc5d578c87d52a96db804e616183bca",
          "message": "run tests on linux and mac",
          "timestamp": "2024-03-16T17:00:48+01:00",
          "tree_id": "d302c670ecb31a8036bbedcbce0006431b3162b0",
          "url": "https://github.com/drexlerd/flatmemory/commit/97d26c584cc5d578c87d52a96db804e616183bca"
        },
        "date": 1710604915970,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41405738.3571428,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41403656 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66559197.45454562,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66558282.9090909 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 431562067.50000334,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 431536468 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140214888.1999949,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140213150.39999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 152635671.25000322,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 152629932.25 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 358944377.00000024,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 358938627.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28378534.63999977,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28377482.400000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63542574.1000006,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 63542481.499999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 391623520.0000102,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 391609298.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20672815.787878733,
            "unit": "ns/iter",
            "extra": "iterations: 33\ncpu: 20672363.84848485 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 51482278.230769046,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 51481495.23076924 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 209161725.3333311,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 209156270.33333334 ns\nthreads: 1"
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
          "id": "7a8c6b47307659d6e46db3fdde100e8e44eda052",
          "message": "remove num cores",
          "timestamp": "2024-03-16T17:04:54+01:00",
          "tree_id": "e3eebc9a7612ba44e5bdc7c6fa4ff11dfdbca72f",
          "url": "https://github.com/drexlerd/flatmemory/commit/7a8c6b47307659d6e46db3fdde100e8e44eda052"
        },
        "date": 1710605156417,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41067300.28571397,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 41063758.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66387992.500000335,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66380641.7 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437610419.9999986,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437584331.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132286332.3999968,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132282208.59999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149049336.0000016,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149046483.59999993 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350190840.5000051,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350183899.5000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28393750.33333269,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28392936.95833333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63209157.27272594,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63208560.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 395098229.0000127,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395094273 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17902803.92307718,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17902531.512820512 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44283877.57142867,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44282613.85714283 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184815102.99999827,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184812241.24999994 ns\nthreads: 1"
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
          "id": "122abd8f1c41d6d346f2cbc432291a8b1214e752",
          "message": "expended unordered_set test",
          "timestamp": "2024-03-17T11:18:33+01:00",
          "tree_id": "760f653e2ccff34dc8353d9448197dbd4d8a015a",
          "url": "https://github.com/drexlerd/flatmemory/commit/122abd8f1c41d6d346f2cbc432291a8b1214e752"
        },
        "date": 1710670774371,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39747734.00000028,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39743200.571428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68227493.50000024,
            "unit": "ns/iter",
            "extra": "iterations: 8\ncpu: 68222212.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 432697601.4999957,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 432693231.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 129327465.80000298,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 129317428.19999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145816430.60000148,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145805943.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 327278113.00000554,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 327264809.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 25846159.666666906,
            "unit": "ns/iter",
            "extra": "iterations: 27\ncpu: 25845132.88888889 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 61312670.9090905,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 61310207.45454545 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 419753601.00001067,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 419726316.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17934870.837837636,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 17934318.297297303 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43280685.68750077,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43278320.062500045 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 183193192.75000367,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 183180890.74999988 ns\nthreads: 1"
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
          "id": "4dd18b5d0146d254dae2abb7200e751890684e97",
          "message": "added missing const",
          "timestamp": "2024-03-17T14:09:51+01:00",
          "tree_id": "d605e177c52eaccb4faea50ff3eb1e9837b05eea",
          "url": "https://github.com/drexlerd/flatmemory/commit/4dd18b5d0146d254dae2abb7200e751890684e97"
        },
        "date": 1710681065348,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39780071.999999225,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39778608.78571428 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68419870.30000213,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68413740.6 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 452208088.9999955,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 449310521.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142640989.19999808,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142634658.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 154059900.2500045,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 154051399.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 371545472.9999976,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 371528192 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26410435.076922588,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26409450.923076928 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64032498.45454504,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64032107.9090909 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 400350995.50000554,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 400336080.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 23983054.24137973,
            "unit": "ns/iter",
            "extra": "iterations: 29\ncpu: 23982046.827586208 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 58794654.166665815,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 58791624.66666666 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 236475339.66666856,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 236464969.3333331 ns\nthreads: 1"
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
          "id": "b7dd00a69f271ca95fde5be170da159166f611b8",
          "message": "added difference on bitset",
          "timestamp": "2024-03-17T14:27:28+01:00",
          "tree_id": "f85ffef703a1f213288578a87bdfeafe01a763a2",
          "url": "https://github.com/drexlerd/flatmemory/commit/b7dd00a69f271ca95fde5be170da159166f611b8"
        },
        "date": 1710682114211,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40292066.00000025,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40292702.50000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68441775.62500064,
            "unit": "ns/iter",
            "extra": "iterations: 8\ncpu: 68441720.625 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 432455802.5000016,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 428851494.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128145861.400003,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128141426.59999995 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144395518.59999824,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144386068.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 332211078.499995,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 332187932.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28025544.20000092,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28023824.76 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63235497.272725895,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63230102.272727296 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 391369197.00000304,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 391353720.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17468062.475000322,
            "unit": "ns/iter",
            "extra": "iterations: 40\ncpu: 17466651.025000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43672486.687500015,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43668774.68749997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 203947247.7499942,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 203943683.99999997 ns\nthreads: 1"
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
          "id": "865dd22a0a1dd329182d56bb7fc812572e890170",
          "message": "make unordered set interface more stl like",
          "timestamp": "2024-04-19T20:58:31+02:00",
          "tree_id": "c1271c571adcb8d8c3b27560255dc8744cf6fe1d",
          "url": "https://github.com/drexlerd/flatmemory/commit/865dd22a0a1dd329182d56bb7fc812572e890170"
        },
        "date": 1713553178428,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40872920.07692265,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40873460.00000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67219567.39999655,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67209664.69999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 442171065.4999913,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 442142205.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 141217119.99999887,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 141213294.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155640107.24999377,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 155637985.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 385259542.99998945,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 385254371.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29201596.416667048,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29201967.70833334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 65627429.09090957,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 65627166.63636363 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396811638.0000026,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396812266.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 23827469.862069473,
            "unit": "ns/iter",
            "extra": "iterations: 29\ncpu: 23827758.13793103 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 53675014.91666833,
            "unit": "ns/iter",
            "extra": "iterations: 12\ncpu: 53673491.583333306 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 198576018.33333167,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 198566357.99999988 ns\nthreads: 1"
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
          "id": "4ebf8744fcd656c7832503b2880e0baa2b83165e",
          "message": "added set_all function to bitset",
          "timestamp": "2024-04-19T22:25:56+02:00",
          "tree_id": "e598a8f142506ca36b3548b120d61c60317b5f03",
          "url": "https://github.com/drexlerd/flatmemory/commit/4ebf8744fcd656c7832503b2880e0baa2b83165e"
        },
        "date": 1713558426010,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39449677.28571466,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39445845.35714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67314849.49999924,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67305528.39999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 440594087.50000274,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 440558776.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 135759437.99999663,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 135748916.79999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151798887.80000395,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 151788632.20000008 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 353814564.0000039,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 353788514.5000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28264930.52000046,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 28262761.519999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 63913440.272727944,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 63912232.72727274 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 394629573.49999785,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 394616386.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18342930.210526206,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18342413.684210524 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46129631.73333166,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46125327.19999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 187442296.4999951,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 187432784.99999994 ns\nthreads: 1"
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
          "id": "f02d7612b4829f2490d95e5c51fc10a48185f76d",
          "message": "removed set all again",
          "timestamp": "2024-04-19T22:27:04+02:00",
          "tree_id": "863ed22aecf6f61abf4a3094562b9e29fe99ef25",
          "url": "https://github.com/drexlerd/flatmemory/commit/f02d7612b4829f2490d95e5c51fc10a48185f76d"
        },
        "date": 1713558486907,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40682011.538461454,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 40681147.92307693 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66991395.090907834,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66988259.63636365 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437348446.9999909,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 436018258.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140608790.4000003,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140602910.80000013 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 151855832.74999458,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 151834702.25000018 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 369419573.00000185,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 369393620.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27688419.159999285,
            "unit": "ns/iter",
            "extra": "iterations: 25\ncpu: 27686983.48 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64283058.00000089,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 64281378.90909091 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 396093320.99999505,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 396076827.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22058954.34375016,
            "unit": "ns/iter",
            "extra": "iterations: 32\ncpu: 22057944.687499996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 51297827.45454618,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 51296351.54545451 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 238530656.66666377,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 238511290.33333328 ns\nthreads: 1"
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
          "id": "bb1e95e2652e3ff786c8317df6eb9898eed30edc",
          "message": "init memory in byte buffer segmented",
          "timestamp": "2024-04-20T16:15:38+02:00",
          "tree_id": "72d8f2b52a79738727afb2b5fa6ab9e2f04656e9",
          "url": "https://github.com/drexlerd/flatmemory/commit/bb1e95e2652e3ff786c8317df6eb9898eed30edc"
        },
        "date": 1713622626857,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39407932.428572066,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39404993.85714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66812151.99999996,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66807540.30000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 436485858.00001174,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 436468344.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136184517.59999743,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136183145.60000008 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149864670.40000093,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149859360.6 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 353775497.0000009,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 353764589.50000036 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27304643.230769224,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27302784.692307692 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66479175.499998175,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66477494.90000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 420521493.4999901,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 420495244.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20816574.40000007,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20815359.942857143 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45579045.714284964,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 45576436.92857142 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 229446121.66666427,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 226765627.99999988 ns\nthreads: 1"
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
          "id": "8673dc2666d744764d0e389ddcc23b883eb0ae68",
          "message": "fixed bug in bitset operations",
          "timestamp": "2024-04-20T17:47:08+02:00",
          "tree_id": "6abfeb3f031b38af118c46299645d4b45aa23642",
          "url": "https://github.com/drexlerd/flatmemory/commit/8673dc2666d744764d0e389ddcc23b883eb0ae68"
        },
        "date": 1713628093893,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40057635.49999943,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40056639.14285715 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67005633.79999949,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67002440.70000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 435810439.5000026,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 435795917.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 141328351.9999993,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 141319644.80000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153465971.39999858,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153456875.60000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 366323365.50000846,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 366319556.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26967270.34615356,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26965491.115384616 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67760360.79999983,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67757228.9 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 422851133.5000036,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 422824829.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21247176.50000003,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 21246330.441176467 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 49096983.461538464,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 49095244.30769229 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 216676732.33333555,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 216658797.66666642 ns\nthreads: 1"
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
          "id": "e8f61ddc40338391c91e44009d1687a57e6c5f63",
          "message": "update find next set bit to use iterators",
          "timestamp": "2024-04-20T18:35:07+02:00",
          "tree_id": "3931b9fd887d773ff5e1a26f091828ee500d74ba",
          "url": "https://github.com/drexlerd/flatmemory/commit/e8f61ddc40338391c91e44009d1687a57e6c5f63"
        },
        "date": 1713630974882,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 37430539.00000051,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 37423055 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 64587864.62500043,
            "unit": "ns/iter",
            "extra": "iterations: 8\ncpu: 64585090.12499999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 431978348.49999595,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 431934830.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 123720108.66666965,
            "unit": "ns/iter",
            "extra": "iterations: 6\ncpu: 123709416.33333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 138373461.99999842,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 138356557.40000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 321708241.500005,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 321676904.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26350644.384615626,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26349846.615384616 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 64720635.80000053,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 64716962.500000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 406913857.5000011,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 406890314.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 16499242.523809563,
            "unit": "ns/iter",
            "extra": "iterations: 42\ncpu: 16498430.214285716 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 41175894.47058796,
            "unit": "ns/iter",
            "extra": "iterations: 17\ncpu: 41174819.05882352 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 179243494.49999964,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 179233540.50000006 ns\nthreads: 1"
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
          "id": "0aad0a79dfb4d798a9fb131426f8bbdc267e72ac",
          "message": "fix is_superseteq of bitset",
          "timestamp": "2024-04-25T19:19:30+02:00",
          "tree_id": "990c1a4266598bea653a192c6bb2b0fbd9f11d0d",
          "url": "https://github.com/drexlerd/flatmemory/commit/0aad0a79dfb4d798a9fb131426f8bbdc267e72ac"
        },
        "date": 1714065640345,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39542321.16666706,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 39541739.05555555 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67771205.40000112,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67757860.7 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 441278027.9999993,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 441265509.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134941275.39999568,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134933632.2000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 145047054.79999983,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 145043486.2 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350529910.5000006,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350519109.00000036 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26517772.30769225,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26516935.57692308 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67175532.00000168,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67174537.2 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 422765981.49999243,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 422753048.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20463683.17647056,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20462616.441176478 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47949492.53845988,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 47948413.92307688 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 197417958.33332768,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 197402107.33333334 ns\nthreads: 1"
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
          "id": "5a3b07e25ca190d9e685c34fae18f43eb289f591",
          "message": "fix assertion",
          "timestamp": "2024-05-05T19:46:59+02:00",
          "tree_id": "28bea9bd1661b04b7440088eb2c3e60a4ab93b3f",
          "url": "https://github.com/drexlerd/flatmemory/commit/5a3b07e25ca190d9e685c34fae18f43eb289f591"
        },
        "date": 1714931286388,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39841996.35714195,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39839311.35714286 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67927361.99999753,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67920533.10000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 439774775.49999833,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 436341954 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 128967969.79999861,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 128958646.00000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 147536972.00000033,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 147532047.4 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 333688099.99998915,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 333660287.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29363538.000000726,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29360892.833333332 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66211864.454546995,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66206086.363636374 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 421476490.50001234,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421431623.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17983814.051281873,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17983158.384615377 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43647160.062500134,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 43643170.12500002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 184560973.25000086,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 184551260.2499999 ns\nthreads: 1"
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
          "id": "f98d91a75026dcea0e095dedae9170377defe904",
          "message": "fix return value",
          "timestamp": "2024-05-05T20:01:55+02:00",
          "tree_id": "ffb90111caa4175469816ce7108b07667a8a2a2a",
          "url": "https://github.com/drexlerd/flatmemory/commit/f98d91a75026dcea0e095dedae9170377defe904"
        },
        "date": 1714932175738,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38443289.16666642,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 38440021.33333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68165672.00000066,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68159997.59999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 435623348.00000715,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 435525285.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132848104.20000212,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132838746.79999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 144534842.60000095,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 144525501.40000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 347887468.50000507,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 347868489.5000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27021884.46153833,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27021272.846153848 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67238890.80000164,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67237661.50000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 420117008.9999948,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 420106941.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20344125.257142715,
            "unit": "ns/iter",
            "extra": "iterations: 35\ncpu: 20343892.428571437 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48462592.384615056,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 48460342.15384616 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 212110122.0000033,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 212110915.33333328 ns\nthreads: 1"
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
          "id": "242b0b4258b668d9cd98fb201155e7ee409199bd",
          "message": "fix are disjoint",
          "timestamp": "2024-05-08T22:45:02+02:00",
          "tree_id": "4c5be0dda51819dcdee2f1bd630f3de3d62eab5f",
          "url": "https://github.com/drexlerd/flatmemory/commit/242b0b4258b668d9cd98fb201155e7ee409199bd"
        },
        "date": 1715201164642,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41512551.61538468,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41511275.15384616 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67061817.80000123,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67058327.7 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437041014.49999654,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437013168 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139094706.20000094,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139089172.59999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 149921879.80000153,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 149911902.59999987 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 379808933.9999962,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 379794001.9999997 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29902109.79166719,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29900809.75 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66882993.699999824,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66873144.19999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 421384554.50000834,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421357693.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 20159110.85294085,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 20158527.38235294 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 49484189.1428572,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 49480950.78571432 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 214918071.3333389,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 214901411.33333325 ns\nthreads: 1"
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
          "id": "fe164117a3ab16403b46a6b2d11fbae64aaf9934",
          "message": "fix is_superset",
          "timestamp": "2024-05-08T22:48:30+02:00",
          "tree_id": "14b53b2ad69829e9fd2de2d25bdee92b17eabc65",
          "url": "https://github.com/drexlerd/flatmemory/commit/fe164117a3ab16403b46a6b2d11fbae64aaf9934"
        },
        "date": 1715201374260,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 41045923.30769317,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 41045077.84615385 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 73666751.14285418,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 73665510.42857142 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 444252676.49999964,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 444242431.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 142976480.19999656,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 142970416.79999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 155067362.20000333,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 155060380.59999996 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 372322750.49998975,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 372309377.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29384545.33333257,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29384379.750000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68328726.20000216,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68324025.80000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 422120451.49999255,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 422035887.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 21093151.55882327,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 21092020.94117647 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 52190405.30769147,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 52189514.07692304 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 232041532.66667047,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 232033777.66666654 ns\nthreads: 1"
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
          "id": "38d960e60c891d0db159bf384ccb1a89b1dfe5dd",
          "message": "added bitset count function",
          "timestamp": "2024-05-13T17:59:59+02:00",
          "tree_id": "062814f25df5467c0a16b74bb0dd0d5c3986f3a8",
          "url": "https://github.com/drexlerd/flatmemory/commit/38d960e60c891d0db159bf384ccb1a89b1dfe5dd"
        },
        "date": 1715616066044,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39038616.21428664,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39035773.071428575 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68312401.49999759,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68307827.9 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 440458562.50001234,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 440411799.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 130802901.60000345,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 130803249.40000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 143569206.19999868,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 143564121.80000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 352925648.50000477,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 352901588.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27858242.42307692,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27855657.884615388 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66711273.19999925,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 66706139.6 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 424126400.5000005,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424085571.4999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19503989.05555536,
            "unit": "ns/iter",
            "extra": "iterations: 36\ncpu: 19502198.61111112 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 45282160.562500454,
            "unit": "ns/iter",
            "extra": "iterations: 16\ncpu: 45281677.625000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 183569744.49999797,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 183558469.9999999 ns\nthreads: 1"
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
          "id": "10a92d7da02df9969c60e8652c6b72e39cbadf19",
          "message": "added actual size to vector type to avoid deallocations",
          "timestamp": "2024-05-13T19:44:14+02:00",
          "tree_id": "94f42448eb704b0a33ad3385ed51955798191246",
          "url": "https://github.com/drexlerd/flatmemory/commit/10a92d7da02df9969c60e8652c6b72e39cbadf19"
        },
        "date": 1715622327243,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 43577917.53846221,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 43572025.30769232 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 74613160.85714234,
            "unit": "ns/iter",
            "extra": "iterations: 7\ncpu: 74611975.85714284 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 470527839.4999937,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 470495651 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 162470868.4999945,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 162460065.25 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 169638282.00000107,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 169615734.7499999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 395085948.49999666,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 395036461.99999976 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27280864.038461827,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27279729.230769236 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68854303.39999914,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68846580.50000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 432704498.5000015,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 432655164.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 22234400.193548437,
            "unit": "ns/iter",
            "extra": "iterations: 31\ncpu: 22233324.387096774 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 58445513.99999886,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 58441379.27272727 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 207532299.3333278,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 207516700.99999973 ns\nthreads: 1"
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
          "id": "b57ee067b01b23b9808cb8bd1b443496fc93a232",
          "message": "added missing initialization in default constructor",
          "timestamp": "2024-05-13T20:00:02+02:00",
          "tree_id": "12940698e34a896a4873622675f7bffd72773fff",
          "url": "https://github.com/drexlerd/flatmemory/commit/b57ee067b01b23b9808cb8bd1b443496fc93a232"
        },
        "date": 1715623300377,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39292983.888889425,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 39290990.55555555 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 69779723.60000136,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 69776758.2 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 441159224.9999927,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 441139343.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 139215733.8000004,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 139210421.00000012 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153788185.3999977,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153782332.2000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 365085174.0000007,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 365071759.5000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27486468.923076868,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27484269.038461532 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67915898.69999939,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67911598.10000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 424808925.9999972,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 424781253.5000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18825401.842105437,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18823589.184210517 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46625503.15384587,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 46619966.692307696 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196620421.00000575,
            "unit": "ns/iter",
            "extra": "iterations: 3\ncpu: 196617203.3333334 ns\nthreads: 1"
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
          "id": "bc56e258515babe18ac7f3d3339fe2c337025813",
          "message": "set m_actual_size to 0 in clear()",
          "timestamp": "2024-05-13T20:16:31+02:00",
          "tree_id": "610b1af41bb69d5c6232911283a7c60ade54c61c",
          "url": "https://github.com/drexlerd/flatmemory/commit/bc56e258515babe18ac7f3d3339fe2c337025813"
        },
        "date": 1715624255580,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40396826.22222231,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 40396866.777777776 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66523044.62500069,
            "unit": "ns/iter",
            "extra": "iterations: 8\ncpu: 66519528.625000015 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 436301471.50000197,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 436292512.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136086169.59999722,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136084171.40000004 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153799925.80000132,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153799617.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 352725370.5000106,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 352708256.0000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29291374.458332818,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29290125.83333334 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 66639497.72727113,
            "unit": "ns/iter",
            "extra": "iterations: 11\ncpu: 66629812.27272727 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 420777993.50001043,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 420751892.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18558024.815789055,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18556086.052631587 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44776263.133331895,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 44776236.13333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 190804404.74999705,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 190787693.99999994 ns\nthreads: 1"
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
          "id": "b4e3cb6f1b2753b1c4e2cf6356194f14aaac98c0",
          "message": "added default constructor for fixed size vector",
          "timestamp": "2024-05-13T21:09:41+02:00",
          "tree_id": "b6f3da89a8634246a21d88950fea4e51fa7b42ec",
          "url": "https://github.com/drexlerd/flatmemory/commit/b4e3cb6f1b2753b1c4e2cf6356194f14aaac98c0"
        },
        "date": 1715627459237,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39318777.99999921,
            "unit": "ns/iter",
            "extra": "iterations: 13\ncpu: 39317234.84615384 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67694100.50000033,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67688687.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437047247.00000954,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 437014859.00000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 132214020.80000076,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 132204295.00000003 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148113642.80000132,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148104084.40000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 342646389.50000405,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 342643773.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 26027217.0384621,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 26026646.269230768 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67535638.39999971,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67451091.70000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 422899642.4999991,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421906034.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 17928773.102563757,
            "unit": "ns/iter",
            "extra": "iterations: 39\ncpu: 17928546.769230768 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 43478993.133334145,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 43475994.933333345 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 185356624.00000063,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 185351957.5 ns\nthreads: 1"
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
          "id": "e4dd49feb66a8d5ffd4d832cfd632c98340d99a2",
          "message": "fixed insert of builder into fixed size type vector",
          "timestamp": "2024-05-13T21:24:40+02:00",
          "tree_id": "a9c33a81078670e9237e1166226b13cdc41e45ec",
          "url": "https://github.com/drexlerd/flatmemory/commit/e4dd49feb66a8d5ffd4d832cfd632c98340d99a2"
        },
        "date": 1715628350985,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39773795.14285774,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39767627.214285724 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67888432.59999737,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67880849.9 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 438142188.0000005,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 438076909.4999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140447921.599997,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140430417.60000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 153762123.39999712,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 153747532.40000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 350117605.50000304,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 350104761.49999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 27147619.5000002,
            "unit": "ns/iter",
            "extra": "iterations: 26\ncpu: 27146151.615384612 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67064335.80000067,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67058522.70000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 421342302.49999404,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421318037.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18813263.36842081,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18812418.81578947 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 44794088.9999988,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 44790874.78571429 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188485959.25000212,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188485433.75000015 ns\nthreads: 1"
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
          "id": "d515d74d2eeb0c1f42dccb1bc6807950e3e6de37",
          "message": ".",
          "timestamp": "2024-05-13T21:58:22+02:00",
          "tree_id": "91d0908b44091d8f04c507d4f78b7a520bb5485d",
          "url": "https://github.com/drexlerd/flatmemory/commit/d515d74d2eeb0c1f42dccb1bc6807950e3e6de37"
        },
        "date": 1715630365968,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 39300985.71428532,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 39299555.14285715 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 68652396.99999961,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68650679.4 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 437919222.4999997,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 436334647.9999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 140912509.99999827,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 140909051.40000007 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 157785114.9999958,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 157770477.20000005 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 369529847.9999991,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 369510233.0000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29092130.79166643,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29086960.58333333 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68954329.99999969,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68951091.49999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 423424889.0000032,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423370644.50000006 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19977854.323529113,
            "unit": "ns/iter",
            "extra": "iterations: 34\ncpu: 19978030.58823529 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 48792348.714286506,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 48787417.14285713 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 196348225.75000045,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 196338160.25000006 ns\nthreads: 1"
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
          "id": "f51739e3d78374872e0dba41c46550d07e7702fc",
          "message": "fixed return value",
          "timestamp": "2024-05-13T22:48:52+02:00",
          "tree_id": "009cbb0bd04980b7464efa8ec0e658b004638c89",
          "url": "https://github.com/drexlerd/flatmemory/commit/f51739e3d78374872e0dba41c46550d07e7702fc"
        },
        "date": 1715633397947,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 40152207.571428075,
            "unit": "ns/iter",
            "extra": "iterations: 14\ncpu: 40144482.857142866 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 67103332.700000346,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67097568.39999999 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 433098832.5000078,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 433064867.5000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 134356714.59999982,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 134348045.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 146143984.20000044,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 146129170.99999994 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 345386011.4999969,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 345346153.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 28854409.99999981,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 28853702.66666667 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 68367286.70000127,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 68351432.20000002 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 421157434.5000031,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 421121659 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 18438441.552631665,
            "unit": "ns/iter",
            "extra": "iterations: 38\ncpu: 18436830.394736838 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 47883135.26666646,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 47881634.93333328 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 188324588.24999776,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 188319877.99999994 ns\nthreads: 1"
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
          "id": "e856b454a661de437ec140ab7f0041b2e5f71507",
          "message": "remove wrong alignment test",
          "timestamp": "2024-05-13T23:16:26+02:00",
          "tree_id": "f66d5027de5a3312c4fa9b0c73cef6459b5a0b4c",
          "url": "https://github.com/drexlerd/flatmemory/commit/e856b454a661de437ec140ab7f0041b2e5f71507"
        },
        "date": 1715635047043,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/1",
            "value": 38541212.77777899,
            "unit": "ns/iter",
            "extra": "iterations: 18\ncpu: 38533894.05555555 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/10",
            "value": 66617625.124997914,
            "unit": "ns/iter",
            "extra": "iterations: 8\ncpu: 66616964.499999985 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderCreate/1000000/100",
            "value": 433057243.5000022,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 433035225 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/1",
            "value": 136345274.39999717,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 136331673.8 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/10",
            "value": 148996271.40000007,
            "unit": "ns/iter",
            "extra": "iterations: 5\ncpu: 148989008.8000001 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetBuilderAccess/1000000/100",
            "value": 347065629.0000136,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 347049489.9999998 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/1",
            "value": 29688658.624999437,
            "unit": "ns/iter",
            "extra": "iterations: 24\ncpu: 29688409.625 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/10",
            "value": 67155206.1,
            "unit": "ns/iter",
            "extra": "iterations: 10\ncpu: 67141356.4 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewCreate/1000000/100",
            "value": 423178143.49999595,
            "unit": "ns/iter",
            "extra": "iterations: 2\ncpu: 423153229.5 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/1",
            "value": 19348053.243242696,
            "unit": "ns/iter",
            "extra": "iterations: 37\ncpu: 19347762.513513517 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/10",
            "value": 46175820.866667055,
            "unit": "ns/iter",
            "extra": "iterations: 15\ncpu: 46172556.13333336 ns\nthreads: 1"
          },
          {
            "name": "flatmemory::benchmarks::BM_BitsetViewAccess/1000000/100",
            "value": 191609469.7499986,
            "unit": "ns/iter",
            "extra": "iterations: 4\ncpu: 191603692.75 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}