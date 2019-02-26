// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SmoothOperator_PTEditorTarget : TargetRules
{
	public SmoothOperator_PTEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "SmoothOperator_PT" } );
	}
}
