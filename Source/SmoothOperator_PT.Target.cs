// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SmoothOperator_PTTarget : TargetRules
{
	public SmoothOperator_PTTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "SmoothOperator_PT" } );
	}
}
