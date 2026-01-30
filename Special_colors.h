//Skaydi 29 Jan 2026
//Please add as needed/desired

#ifndef __SPECIAL_COLORS_H__
#define __SPECIAL_COLORS_H__

#include <array>
#include <map>
#include <vector>
#include <string>

#include <TColor.h>

class Skaydis_colors
{
   	public:
		Skaydis_colors(){
			MakeGradients();
		}
		
		~Skaydis_colors(){};
		
		void MakeGradients()
		{
			//turn the colors into the gradients that are stored in the ints
			for(auto gay:this->Flags){
				for(auto color:gay.second)
				{
					for(auto rgb:color){
						if(rgb > 1){
							convert_rgb(&color);
							break;
						}
					}
				}
			       	makeGradient(gay.first, gay.second);	
			}
			return;	
		}
		
		void convert_rgb(std::array<float, 3>* color_RGB)
		{
			for(int i=0; i<3; i++) color_RGB->at(i)=color_RGB->at(i)/255.;
			return;
		}

		void makeGradient(LABEL label, std::vector<std::array<float, 3>> colors) 
		{
			int n_colors = (int) colors.size();
			
			if(n_colors == 2) 
			{
				Double_t Red[2]	= 	{ colors.at(0).at(0), colors.at(1).at(0)};

				Double_t Green[2] = 	{ colors.at(0).at(1), colors.at(1).at(1)};

				Double_t Blue[2] = 	{ colors.at(0).at(2), colors.at(1).at(2)};
				if(label == LABEL::trans) 
				{
					Trans_gradient = TColor::CreateColorGradientTable(2, stops_two, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Trans_gradient_PT[i]=i+Trans_gradient;

					Trans_log_gradient = TColor::CreateColorGradientTable(2, stops_two, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Trans_log_gradient_PT[i]=i+Trans_log_gradient;
				}
			}
			else if(n_colors == 3) 
			{
				Double_t Red[3]	= 	{ colors.at(0).at(0), colors.at(1).at(0), colors.at(2).at(0) };
				Double_t Green[3] = 	{ colors.at(0).at(1), colors.at(1).at(1), colors.at(2).at(1) };
				Double_t Blue[3] = 	{ colors.at(0).at(2), colors.at(1).at(2), colors.at(2).at(2) };
				
				if(label == LABEL::enby) 
				{
					Enby_gradient = TColor::CreateColorGradientTable(3, stops_three_lin, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Enby_gradient_PT[i]=i+Enby_gradient;

					Enby_log_gradient = TColor::CreateColorGradientTable(3, stops_three_log, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Enby_log_gradient_PT[i]=i+Enby_log_gradient;
				}
						
				else if(label == LABEL::bi) 
				{
					Bi_gradient = TColor::CreateColorGradientTable(3, stops_three_lin, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Bi_gradient_PT[i]=i+Bi_gradient;

					Bi_log_gradient = TColor::CreateColorGradientTable(3, stops_three_log, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Bi_log_gradient_PT[i]=i+Bi_log_gradient;
				}
			}
			else if(n_colors == 6) 
			{
				Double_t Red[6]	= 	{ colors.at(0).at(0), colors.at(1).at(0), colors.at(2).at(0),
			       				  colors.at(3).at(0), colors.at(4).at(0), colors.at(5).at(0)};

				Double_t Green[6] = 	{ colors.at(0).at(1), colors.at(1).at(1), colors.at(2).at(1) ,
			       				  colors.at(3).at(1), colors.at(4).at(1), colors.at(5).at(1)};

				Double_t Blue[6] = 	{ colors.at(0).at(2), colors.at(1).at(2), colors.at(2).at(2) ,
			       				  colors.at(3).at(2), colors.at(4).at(2), colors.at(5).at(2)};
				if(label == LABEL::lesbian) 
				{
					Lesbian_gradient = TColor::CreateColorGradientTable(6, stops_six_lin, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Lesbian_gradient_PT[i]=i+Lesbian_gradient;

					Lesbian_log_gradient = TColor::CreateColorGradientTable(6, stops_six_log, Red, Green, Blue, 100);
					for(int i=0; i<100; i++) Lesbian_log_gradient_PT[i]=i+Lesbian_log_gradient;
				}
			}
			return;
		}

		//colors stored in RGB values
		std::array<float, 3> enby_yellow 		{252., 244., 52.};
		std::array<float, 3> enby_purple 		{156., 89., 209.};

		std::array<float, 3> trans_blue 		{0., 202., 250.};
		std::array<float, 3> trans_pink 		{239., 60., 235.};
		
		std::array<float, 3> lesbian_deep_orange	{213., 45., 0.};
		std::array<float, 3> lesbian_mid_orange		{239., 118., 39.};
		std::array<float, 3> lesbian_light_orange	{255., 154., 86.};
		std::array<float, 3> lesbian_light_pink		{209., 98., 164.};
		std::array<float, 3> lesbian_mid_pink		{181., 86., 144.};
		std::array<float, 3> lesbian_deep_pink		{162., 2., 98.};
		
		std::array<float, 3> bi_blue 			{0., 56., 168.};
		std::array<float, 3> bi_purple			{155., 79., 150.};
		std::array<float, 3> bi_pink 			{214., 2., 112.};

		Int_t Enby_gradient, 	Enby_log_gradient;
		Int_t Trans_gradient, 	Trans_log_gradient;
		Int_t Lesbian_gradient, Lesbian_log_gradient;
	        Int_t Bi_gradient,	Bi_log_gradient;
		
		Int_t Enby_gradient_PT [100], 	Enby_log_gradient_PT [100];
		Int_t Trans_gradient_PT [100], 	Trans_log_gradient_PT [100];
		Int_t Lesbian_gradient_PT [100], Lesbian_log_gradient_PT [100];
	        Int_t Bi_gradient_PT [100],	Bi_log_gradient_PT [100];
		
		Double_t stops_three_lin[3] = 	{0, 0.6, 1.};
		Double_t stops_three_log[3] = 	{0, 0.75, 1.};
		
		Double_t stops_six_lin[6] = 	{0, 0.2, 0.4, 0.6, 0.8, 1.};
		Double_t stops_six_log[6] = 	{0, 0.6, 0.8, 0.9, 0.95, 1.};
		
		Double_t stops_four_lin[4] = 	{0, 0.33, 0.67, 1.};
		Double_t stops_four_log[4] = 	{0, 0.5, 0.75, 1.};
	
		Double_t stops_two[2] 	=	{0., 1.};

		std::map<LABEL, std::vector<std::array<float, 3>> Flags
		{
			{LABEL::enby, 		std::vector<std::array<float, 3>> {enby_yellow, enby_purple, {0., 0., 0.}}},
			{LABEL::trans, 		std::vector<std::array<float, 3>> {trans_blue, trans_pink}},
		       	{LABEL::lesbian, 	std::vector<std::array<float, 3>> 
				{lesbian_deep_orange, lesbian_mid_orange, lesbian_light_orange, 
					lesbian_light_pink, lesbian_mid_pink, lesbian_deep_pink}},
			{LABEL::bi, 		std::vector<std::array<float, 3>> {bi_blue, bi_purple, bi_pink}}
		};
		
		enum LABEL
		{
			enby = 1;
			trans = 2;
			lesbian = 3;
			bi = 4; //please feel free to expand
		};
};
#endif
