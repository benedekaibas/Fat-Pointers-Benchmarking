use std::time::Instant;
use rayon::prelude::*;

const N: usize = 20000;

fn init_arrays(a: &mut [f64], b: &mut [f64]) {
    for i in 0..N {
        a[i] = 1.0;
        b[i] = 1.0;
    }
}

fn func2(mut i: f64, mut j: f64) -> f64 {
    let mut res = 0.0;
    while i / j > 0.0 {
        res += i / j;
        i -= 0.1;
        j -= 0.000003;
    }
    res
}

fn single_thread(a: &[f64], b: &[f64]) -> f64 {
    let mut res = 0.0;
    for i in 0..N {
        for j in 0..N {
            if i == j { continue; }
            res += func2(a[i], b[j]);
        }
    }
    res
}

fn multi_threads(a: &[f64], b: &[f64]) -> f64 {
    (0..N).into_par_iter().map(|i| {
        let mut res = 0.0;
        for j in 0..N {
            if i == j { continue; }
            res += func2(a[i], b[j]);
        }
        res
    }).sum()
}

fn main() {
    let mut a = vec![0.0; N];
    let mut b = vec![0.0; N];
    init_arrays(&mut a, &mut b);

    let start_time = Instant::now();
    let res = single_thread(&a, &b);
    let elapsed_time = start_time.elapsed().as_secs_f64();
    println!("Default:  Done with {} in {} sd", res, elapsed_time);

    let start_time = Instant::now();
    let res = multi_threads(&a, &b);
    let elapsed_time = start_time.elapsed().as_secs_f64();
    println!("With OMP: Done with {} in {} sd", res, elapsed_time);
}
