



use std::io::{self, Read};

fn alpha(speed: f64) -> f64{
	//speed is a factor of c
	let l = (1.0 - (speed * speed)).sqrt();
//	assert!(!l.is_nan());

	return l;
}

fn wait(p: usize, times: &mut [f64], played: &mut [bool], speeds: & [f64]){
	times[p] += alpha(speeds[p]);
	played[p] = true;
}

fn play(p: usize, times: &mut [f64], played: &mut [bool], speeds: & [f64]) {
	if played[p] {
		println!("player {} can't play, he's already played!", p);
	} else {
		if times[p] < 1.0f64 {
			println!("{}'s turn isn't yet due; waiting...", p);
			wait(p, times, played, speeds);
		} else {
			println!("{} plays", p);
			times[p] -= 1.0f64;
			played[p] = true;
		}
	}

}

fn print_pf(p: usize, speeds: &[f64], times: &[f64]){
	println!("player {} stats:", p);
	println!("speed: {}", speeds[p]);
	println!("factor: {}", alpha(speeds[p]));
	println!("turn counter: {}", times[p]);
}

fn main() {
	const P: usize = 2;

	let mut times = [0.0f64; P];
	let /*mut*/speeds = [0.0f64; P];
	let mut played = [false; P];

	let mut buf = [' ' as u8; 2];

	loop {
		print_pf(0, &speeds, &times);
		print_pf(1, &speeds, &times);
		
		io::stdin().read(&mut buf).expect("asd");
		let input = buf[0] as char;

		if input == '1' { play(0, &mut times, &mut played, &speeds); }
		else if input == '2' { play(1, &mut times, &mut played, &speeds); }
		else if input == ' ' {
			played[0] = false;
			played[1] = false;
		} 

	}
}
