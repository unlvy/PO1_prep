#pragma once
#include <iostream>
#include "Policy.h"

#define MyCalculation(name, cPolicy, vPolicy) 								\
		class name : public CachePolicy, public VerbosityPolicy { 			\
		public: 															\
			name() {														\
				CachePolicy::_name = #cPolicy;								\
				VerbosityPolicy::_name = #vPolicy;							\
				lastArg = lastVal = 0.0;									\
			}																\
																			\
			void cacheValueForArgument(double arg, double val) override {	\
				lastArg = arg;												\
				lastVal = val;												\
			}																\
																			\
			bool hasCacheFor(double arg) const override {					\
				if (CachePolicy::policyName() == "OneCallCache"				\
					&& lastArg == arg) {									\
					return true;											\
				} else {													\
					return false;											\
				}															\
			}																\
																			\
			double getCached(double arg) const override {					\
				return lastVal;												\
			}																\
																			\
			void printArgAndResult(double arg, double val) const override {	\
				if (VerbosityPolicy::policyName() == "Verbose") {			\
					std::cout << "f(" << lastArg << ") = " 					\
						  << lastVal << std::endl;							\
				}															\
			}																\
																			\
			void eval(double x) { 											\
				if (hasCacheFor(x)) {										\
					return;													\
				} 															\
				cacheValueForArgument(x, sqrt(pow(x - 7, 2)));				\
				printArgAndResult(x, getCached(x));							\
			} 																\
		}; 
